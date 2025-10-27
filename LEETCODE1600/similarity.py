import re, zss
# Compute similarity of c and rust by normalizing rust to c
def similarity(c_sexpr: str, r_sexpr: str) -> float:
    def parse_sexpr(s: str):
        # drop field labels like "type:", "left:", etc.
        s = re.sub(r'\b[A-Za-z_]+:\s*', '', s)
        toks = re.findall(r'\(|\)|[^\s()]+', s)

        def parse_at(i: int):
            # expects '(' at toks[i]
            if i >= len(toks) or toks[i] != '(':
                return None, i
            i += 1
            # allow empty parens just in case: ()
            if i >= len(toks):
                return ("nil", []), i
            label = toks[i]
            i += 1
            children = []
            while i < len(toks):
                t = toks[i]
                if t == '(':
                    child, i = parse_at(i)
                    if child is not None:
                        children.append(child)
                elif t == ')':
                    i += 1
                    break
                else:
                    # bare atoms inside lists: ignore (tree-sitter usually wraps as (node ...))
                    i += 1
            return (label, children), i

        roots = []
        i = 0
        while i < len(toks):
            if toks[i] == '(':
                node, i = parse_at(i)
                if node is not None:
                    roots.append(node)
            else:
                i += 1
        if not roots:
            return ("program", [])
        # if multiple top-level forms, wrap them
        return ("program", roots if len(roots) > 1 else [roots[0]])

    c_tree = parse_sexpr(c_sexpr)
    r_tree = parse_sexpr(r_sexpr)

    # normalization variables
    DROP = {
        "comment","identifier","type_identifier","primitive_type","field_identifier",
        "number_literal","char_literal","string_literal","boolean_literal",
        "escape_sequence","attribute_item","visibility_modifier",
        "mutable_specifier","const_qualifier","type_qualifier","scoped_identifier",
        "type_arguments","generic_type","lifetime","reference_type","pointer_type",
    }
    WRAP = {"expression_statement","parenthesized_expression"}
    C_BLOCK, RS_BLOCK = "compound_statement", "block"

    def unwrap(node):
        k, kids = node
        return kids[0] if k in WRAP and len(kids) == 1 else None

    # infer C style to rust
    def walk(node):
        k, kids = node
        yield k
        for ch in kids:
            yield from walk(ch)

    c_kinds = set(walk(c_tree))
    has_for    = "for_statement" in c_kinds
    has_while  = "while_statement" in c_kinds
    has_switch = "switch_statement" in c_kinds
    loop_pref  = "for" if has_for or not has_while else "while"

    # normalization (based on c and normalize rust)
    def norm(node, lang):
        if node is None: return None
        k, kids = node
        if k in DROP: return None
        u = unwrap(node)
        if u is not None: return norm(u, lang)

        def K(kind, children=None):
            return (kind, [c for c in (children or []) if c is not None])

        if lang == "c":
            if k == "function_definition":
                body = next((ch for ch in kids if ch[0] == C_BLOCK), None)
                return K("fn", [norm(body, lang)])
            if k == C_BLOCK:
                xs = [norm(ch, lang) for ch in kids]
                # relax order for a leading run of declarations/binds
                i, lead = 0, []
                while i < len(xs) and xs[i] and xs[i][0] == "bind":
                    lead.append(xs[i]); i += 1
                if lead:
                    lead.sort(key=lambda x: len(x[1]))
                    xs = lead + xs[i:]
                return K("block", xs)
            if k == "if_statement":
                parts = []
                for ch in kids:
                    if ch[0] == "else_clause":
                        b = next((norm(g, lang) for g in ch[1] if norm(g, lang)), None)
                        parts.append(("else", [b] if b else []))
                    else:
                        parts.append(norm(ch, lang))
                parts = [p for p in parts if p]
                if parts: parts[0] = ("cond", [])
                return K("if", parts)
            if k == "for_statement":
                body = next((ch for ch in kids if ch[0] == C_BLOCK), None)
                return K("for", [norm(body, lang)])
            if k == "while_statement":
                body = next((ch for ch in kids if ch[0] == C_BLOCK), None)
                return K("while", [norm(body, lang)])
            if k == "switch_statement":
                arms = []
                for ch in kids:
                    if ch[0] in ("switch_case","default_case"):
                        b = next((norm(g, lang) for g in ch[1] if norm(g, lang)), None)
                        arms.append(("case", [b] if b else []))
                return K("switch", arms)
            if k == "return_statement": return ("ret", [])
            if k == "call_expression":   return ("call", [])
            if k in ("declaration","init_declarator"): return ("bind", [])
            if k in ("break_statement","continue_statement"): return ("ctrl", [])

        else:  # rust to C-like
            if k == "function_item":
                body = next((ch for ch in kids if ch[0] == RS_BLOCK), None)
                return K("fn", [norm(body, lang)])
            if k == RS_BLOCK:
                xs = [norm(ch, lang) for ch in kids]
                i, lead = 0, []
                while i < len(xs) and xs[i] and xs[i][0] == "bind":
                    lead.append(xs[i]); i += 1
                if lead:
                    lead.sort(key=lambda x: len(x[1]))
                    xs = lead + xs[i:]
                return K("block", xs)
            if k == "if_expression":
                parts = []
                for ch in kids:
                    if ch[0] == "else_clause":
                        b = next((norm(g, lang) for g in ch[1] if norm(g, lang)), None)
                        parts.append(("else", [b] if b else []))
                    else:
                        parts.append(norm(ch, lang))
                parts = [p for p in parts if p]
                if parts: parts[0] = ("cond", [])
                return K("if", parts)
            if k in ("for_expression","while_expression","loop_expression"):
                body = next((ch for ch in kids if ch[0] == RS_BLOCK), None)
                kind = "for" if loop_pref == "for" else "while"
                return K(kind, [norm(body, lang)])
            if k == "match_expression":
                arms = []
                for ch in kids:
                    if ch[0] == "match_arm":
                        b = next((norm(g, lang) for g in ch[1] if norm(g, lang)), None)
                        arms.append(("case", [b] if b else []))
                return K("switch", arms) if has_switch else K("if", arms)
            if k == "return_expression":                 return ("ret", [])
            if k in ("call_expression","macro_invocation"): return ("call", [])
            if k == "let_declaration":                   return ("bind", [])
            if k in ("break_expression","continue_expression"): return ("ctrl", [])

        # bubble up normalized children
        chs = [norm(ch, lang) for ch in kids]
        chs = [c for c in chs if c is not None]
        if not chs: return None
        return ("grp", chs)

    c_norm = ("program", [n for n in (norm(ch, "c") for ch in c_tree[1]) if n])
    r_norm = ("program", [n for n in (norm(ch, "rust") for ch in r_tree[1]) if n])

    # ZSS tree similarity
    def to_zss(t):
        k, kids = t
        z = zss.Node(k)
        for c in kids:
            z.addkid(to_zss(c))
        return z
    def count(t):
        return 1 + sum(count(c) for c in t[1]) if t else 0

    zc, zr = to_zss(c_norm), to_zss(r_norm)
    ted = zss.simple_distance(zc, zr)
    denom = max(count(c_norm), count(r_norm), 1)
    return max(0.0, 1.0 - ted/denom)


# Similarity within each language to remove the duplicates
def similarity_same_lang(ast_text_a: str, ast_text_b: str, lang: str = "c") -> float:

    def sexpr_to_tuple(s: str):
        s = re.sub(r'\b[A-Za-z_]+:\s*', '', s)        
        toks = re.findall(r'\(|\)|[^\s()]+', s)

        def parse_at(i):
            if i >= len(toks) or toks[i] != '(': return None, i
            i += 1
            label = toks[i] if i < len(toks) else "nil"; i += 1
            kids = []
            while i < len(toks):
                t = toks[i]
                if t == '(':
                    ch, i = parse_at(i)
                    if ch is not None: kids.append(ch)
                elif t == ')':
                    i += 1; break
                else:
                    i += 1
            return (label, kids), i

        roots, i = [], 0
        while i < len(toks):
            if toks[i] == '(':
                n, i = parse_at(i)
                if n is not None: roots.append(n)
            else:
                i += 1
        if not roots: return ("program", [])
        return ("program", roots if len(roots) > 1 else [roots[0]])

    DROP = {
        "comment","identifier","type_identifier","primitive_type","field_identifier",
        "number_literal","char_literal","string_literal","boolean_literal",
        "escape_sequence","attribute_item","visibility_modifier",
        "mutable_specifier","const_qualifier","type_qualifier","scoped_identifier",
        "type_arguments","generic_type","lifetime","reference_type","pointer_type",
    }
    WRAP = {"expression_statement","parenthesized_expression"}

    def unwrap(node):
        k, kids = node
        return kids[0] if k in WRAP and len(kids) == 1 else None

    def K(kind, kids=None):
        return (kind, [c for c in (kids or []) if c is not None])

    # --- C normalization ---
    def norm_c(node):
        if node is None: return None
        k, kids = node
        if k in DROP: return None
        u = unwrap(node)
        if u is not None: return norm_c(u)

        if k == "function_definition":
            body = next((c for c in kids if c[0] == "compound_statement"), None)
            return K("fn", [norm_c(body)])
        if k == "compound_statement":
            xs = [norm_c(c) for c in kids]
            # relax leading declarations
            i, lead = 0, []
            while i < len(xs) and xs[i] and xs[i][0] == "bind":
                lead.append(xs[i]); i += 1
            if lead:
                lead.sort(key=lambda x: len(x[1]))
                xs = lead + xs[i:]
            return K("block", xs)
        if k == "if_statement":
            parts = []
            for ch in kids:
                if ch[0] == "else_clause":
                    b = next((norm_c(g) for g in ch[1] if norm_c(g)), None)
                    parts.append(("else", [b] if b else []))
                else:
                    parts.append(norm_c(ch))
            parts = [p for p in parts if p]
            if parts: parts[0] = ("cond", [])
            return K("if", parts)
        if k in ("for_statement","while_statement"):
            body = next((c for c in kids if c[0] == "compound_statement"), None)
            return K("loop", [norm_c(body)])  # unify loops for dedup
        if k == "switch_statement":
            arms = []
            for ch in kids:
                if ch[0] in ("switch_case","default_case"):
                    b = next((norm_c(g) for g in ch[1] if norm_c(g)), None)
                    arms.append(("case", [b] if b else []))
            return K("switch", arms)
        if k == "return_statement": return ("ret", [])
        if k == "call_expression":  return ("call", [])
        if k in ("declaration","init_declarator"): return ("bind", [])
        if k in ("break_statement","continue_statement"): return ("ctrl", [])

        chs = [norm_c(c) for c in kids]
        chs = [c for c in chs if c]
        return ("grp", chs) if chs else None

    # --- Rust normalization ---
    def norm_rust(node):
        if node is None: return None
        k, kids = node
        if k in DROP: return None
        u = unwrap(node)
        if u is not None: return norm_rust(u)

        if k == "function_item":
            body = next((c for c in kids if c[0] == "block"), None)
            return K("fn", [norm_rust(body)])
        if k == "block":
            xs = [norm_rust(c) for c in kids]
            i, lead = 0, []
            while i < len(xs) and xs[i] and xs[i][0] == "bind":
                lead.append(xs[i]); i += 1
            if lead:
                lead.sort(key=lambda x: len(x[1]))
                xs = lead + xs[i:]
            return K("block", xs)
        if k == "if_expression":
            parts = []
            for ch in kids:
                if ch[0] == "else_clause":
                    b = next((norm_rust(g) for g in ch[1] if norm_rust(g)), None)
                    parts.append(("else", [b] if b else []))
                else:
                    parts.append(norm_rust(ch))
            parts = [p for p in parts if p]
            if parts: parts[0] = ("cond", [])
            return K("if", parts)
        if k in ("for_expression","while_expression","loop_expression"):
            body = next((c for c in kids if c[0] == "block"), None)
            return K("loop", [norm_rust(body)])  # unify loops
        if k == "match_expression":
            arms = []
            for ch in kids:
                if ch[0] == "match_arm":
                    b = next((norm_rust(g) for g in ch[1] if norm_rust(g)), None)
                    arms.append(("case", [b] if b else []))
            return K("switch", arms)
        if k == "return_expression":                 return ("ret", [])
        if k in ("call_expression","macro_invocation"): return ("call", [])
        if k == "let_declaration":                   return ("bind", [])
        if k in ("break_expression","continue_expression"): return ("ctrl", [])

        chs = [norm_rust(c) for c in kids]
        chs = [c for c in chs if c]
        return ("grp", chs) if chs else None

    # parse and normalize
    A = sexpr_to_tuple(ast_text_a.strip())
    B = sexpr_to_tuple(ast_text_b.strip())
    if lang == "c":
        A = ("program", [x for x in (norm_c(ch) for ch in A[1]) if x])
        B = ("program", [x for x in (norm_c(ch) for ch in B[1]) if x])
    else:
        A = ("program", [x for x in (norm_rust(ch) for ch in A[1]) if x])
        B = ("program", [x for x in (norm_rust(ch) for ch in B[1]) if x])

    # zss similarity
    def to_zss(t):
        k, kids = t
        node = zss.Node(k)
        for c in kids: node.addkid(to_zss(c))
        return node
    def count(t): return 1 + sum(count(c) for c in t[1]) if t else 0

    za, zb = to_zss(A), to_zss(B)
    ted = zss.simple_distance(za, zb)
    denom = max(count(A), count(B), 1)
    return max(0.0, 1.0 - ted/denom)
