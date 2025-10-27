import os, json, shutil
from tqdm import tqdm
from tree_sitter import Language, Parser
import tree_sitter_c as tsc
import tree_sitter_rust as tsr
from similarity import similarity, similarity_same_lang


# Helper function to convert tree-sitter node to S-expression format
def node_to_sexp(node):
    """Convert a tree-sitter node to S-expression format"""
    if node.child_count == 0:
        # Leaf node
        return f"({node.type})"
    else:
        # Internal node with children
        children = " ".join(node_to_sexp(child) for child in node.children)
        return f"({node.type} {children})"


# Setup languages and parsers
C_LANGUAGE = Language(tsc.language())
RUST_LANGUAGE = Language(tsr.language())

# Create separate parsers for each language
parser_c = Parser(C_LANGUAGE)
parser_rust = Parser(RUST_LANGUAGE)

def code2AST(data_dir="LEETCODE1600", outdir="LEETCODE_AST"):
    """Convert C and Rust code files to AST representations and save original code"""
    all_codes = {}
    for filename in tqdm(os.listdir(data_dir), desc="Fetching all codes"):
        problem_dir = os.path.join(data_dir, filename)
        
        if os.path.isdir(problem_dir) and os.listdir(problem_dir):
            c_dir = os.path.join(problem_dir, "c")
            rust_dir = os.path.join(problem_dir, "rust")
            
            # C list
            c_code_list = []
            if os.path.exists(c_dir):
                c_list = os.listdir(c_dir)
                for c_file in c_list:
                    with open(os.path.join(c_dir, c_file), 'r') as f:
                        c_code_list.append(f.read())
            # Rust code
            rust_code_list = []
            if os.path.exists(rust_dir):
                rust_list = os.listdir(rust_dir)
                for rust_file in rust_list:
                    with open(os.path.join(rust_dir, rust_file), 'r') as f:
                        rust_code_list.append(f.read())
            
            all_codes[filename] = {'c': c_code_list, 'rust': rust_code_list}
    
    # to ast structure
    for key in tqdm(all_codes, desc="Converting to AST"):
        # Create output directories for AST and original code
        os.makedirs(os.path.join(outdir, key, "rust_ast"), exist_ok=True)
        os.makedirs(os.path.join(outdir, key, "c_ast"), exist_ok=True)
        os.makedirs(os.path.join(outdir, key, "rust_code"), exist_ok=True)
        os.makedirs(os.path.join(outdir, key, "c_code"), exist_ok=True)
        
        # Process Rust codes
        rust_codes = all_codes[key]['rust']
        
        for index, rust_content in enumerate(rust_codes, 1):
            # Save original Rust code
            code_output_path = os.path.join(outdir, key, "rust_code", f"{index}.rs")
            with open(code_output_path, "w") as f:
                f.write(rust_content)
            
            # Encode and parse
            rust_encode = rust_content.encode("utf-8")
            rust_ast = parser_rust.parse(rust_encode)  # Use parser_rust
            
            # Save AST with numbered filename
            ast_output_path = os.path.join(outdir, key, "rust_ast", f"{index}.txt")
            with open(ast_output_path, "w") as f:
                f.write(node_to_sexp(rust_ast.root_node))
        
        # Process C codes
        c_codes = all_codes[key]['c']
        
        for index, c_content in enumerate(c_codes, 1):
            # Save original C code
            code_output_path = os.path.join(outdir, key, "c_code", f"{index}.c")
            with open(code_output_path, "w") as f:
                f.write(c_content)
            
            # Encode and parse
            c_encode = c_content.encode("utf-8")
            c_ast = parser_c.parse(c_encode)  # Use parser_c
            
            # Save AST with numbered filename
            ast_output_path = os.path.join(outdir, key, "c_ast", f"{index}.txt")
            with open(ast_output_path, "w") as f:
                f.write(node_to_sexp(c_ast.root_node))
    
    print(f"\nCompleted! ASTs and original code saved to {outdir}")
    return all_codes

def _dedup_lang(ast_dir, code_dir, out_code_dir, out_ast_dir, ext, lang, threshold):
    """
    remove potentially structually duplicate c and rust codes
    """
    files = sorted([f for f in os.listdir(ast_dir) if f.endswith(".txt")])
    kept, dropped = [], set()

    for i in range(len(files)):
        fi = files[i]
        if fi in dropped:
            continue

        kept.append(os.path.splitext(fi)[0])
        with open(os.path.join(ast_dir, fi), "r", encoding="utf-8") as f:
            s_i = f.read().strip()

        for j in range(i + 1, len(files)):
            fj = files[j]
            if fj in dropped:
                continue
            with open(os.path.join(ast_dir, fj), "r", encoding="utf-8") as g:
                s_j = g.read().strip()
            if similarity_same_lang(s_i, s_j, lang=lang) >= threshold:
                dropped.add(fj)

    os.makedirs(out_code_dir, exist_ok=True)
    os.makedirs(out_ast_dir,  exist_ok=True)
    for base in kept:
        shutil.copy(os.path.join(code_dir, f"{base}.{ext}"), os.path.join(out_code_dir, f"{base}.{ext}"))
        shutil.copy(os.path.join(ast_dir,  f"{base}.txt"),   os.path.join(out_ast_dir,  f"{base}.txt"))
    return kept, len(files)


def dedup_dataset(data_dir="LEETCODE_AST", outdir="LEETCODE_DEDUP", duplicate_threshold=0.80):
    summary = {"_threshold": duplicate_threshold, "_totals": {"c_total": 0, "c_kept": 0, "rust_total": 0, "rust_kept": 0}}

    for prob in tqdm(sorted(os.listdir(data_dir)), desc="Dedup C & Rust per problem"):
        prob_dir      = os.path.join(data_dir, prob)
        c_ast_dir     = os.path.join(prob_dir, "c_ast")
        rust_ast_dir  = os.path.join(prob_dir, "rust_ast")
        c_code_dir    = os.path.join(prob_dir, "c_code")
        rust_code_dir = os.path.join(prob_dir, "rust_code")
        if not (os.path.isdir(c_ast_dir) and os.path.isdir(rust_ast_dir)):
            continue

        out_prob  = os.path.join(outdir, prob)
        c_code_o  = os.path.join(out_prob, "c_code")
        c_ast_o   = os.path.join(out_prob, "c_ast")
        r_code_o  = os.path.join(out_prob, "rust_code")
        r_ast_o   = os.path.join(out_prob, "rust_ast")

        c_kept, c_total = _dedup_lang(c_ast_dir,   c_code_dir,   c_code_o, c_ast_o, ext="c",  lang="c",   threshold=duplicate_threshold)
        r_kept, r_total = _dedup_lang(rust_ast_dir, rust_code_dir, r_code_o, r_ast_o, ext="rs", lang="rust", threshold=duplicate_threshold)

        summary[prob] = {
            "c_total": c_total,   "c_kept": len(c_kept),   "c_kept_basenames": c_kept,
            "rust_total": r_total,"rust_kept": len(r_kept),"rust_kept_basenames": r_kept,
        }
        summary["_totals"]["c_total"]  += c_total
        summary["_totals"]["c_kept"]   += len(c_kept)
        summary["_totals"]["rust_total"] += r_total
        summary["_totals"]["rust_kept"]  += len(r_kept)

    os.makedirs(outdir, exist_ok=True)
    with open(os.path.join(outdir, "dedup_summary.json"), "w", encoding="utf-8") as f:
        json.dump(summary, f, indent=2, ensure_ascii=False)

    print(f"\n Dedup done. Threshold={duplicate_threshold}")
    print(f"   C kept:    {summary['_totals']['c_kept']} / {summary['_totals']['c_total']}")
    print(f"   Rust kept: {summary['_totals']['rust_kept']} / {summary['_totals']['rust_total']}")
    return summary

# Pairing rust based on c

def filter_pairs(data_dir="LEETCODE_DEDUP",
                 outdir="LEETCODE_PAIRED",
                 threshold=[0.85, 0.70, 0.60]):
    """
    For each C AST, pick at most one Rust per band:
      [t0, +inf), [t1, t0), [t2, t1)
    where t0 >= t1 >= t2 from `threshold`.
    Copies the matched .c and .rs into pair_* folders and
    writes scores into the summary dict.
    """
    t = sorted(threshold, reverse=True)
    bands = [(t[0], float("inf")), (t[1], t[0]), (t[2], t[1])]

    def ast_files(d):
        return sorted(f for f in os.listdir(d) if f.endswith(".txt"))

    summary = {}
    total_pairs = 0
    pbar = tqdm(sorted(os.listdir(data_dir)))
    for prob in pbar:
        pbar.set_description(f"Pairing C2Rust: {prob}")

        prob_dir = os.path.join(data_dir, prob)
        c_ast_dir     = os.path.join(prob_dir, "c_ast")
        rust_ast_dir  = os.path.join(prob_dir, "rust_ast")
        c_code_dir    = os.path.join(prob_dir, "c_code")
        rust_code_dir = os.path.join(prob_dir, "rust_code")

        if not (os.path.isdir(c_ast_dir) and os.path.isdir(rust_ast_dir)):
            continue

        c_files = ast_files(c_ast_dir)
        r_files = ast_files(rust_ast_dir)

        summary[prob] = {}
        pair_count = 0

        for c_ast_file in c_files:
            with open(os.path.join(c_ast_dir, c_ast_file), "r", encoding="utf-8") as f:
                c_text = f.read().strip()
            c_key = os.path.splitext(c_ast_file)[0]

            # compute all C2Rust similarities once
            results = []
            for rust_ast_file in r_files:
                with open(os.path.join(rust_ast_dir, rust_ast_file), "r", encoding="utf-8") as f:
                    r_text = f.read().strip()
                score = similarity(c_text, r_text)
                r_key = os.path.splitext(rust_ast_file)[0]
                results.append((score, r_key))

            # pick top-1 per band
            picked = {}
            for low, high in bands:
                cands = [(s, r) for (s, r) in results if low <= s < high]
                if cands:
                    s, rbest = max(cands, key=lambda x: x[0])
                    picked[rbest] = float(f"{s:.6f}")  # keep score

            if not picked:
                continue

            summary[prob][c_key] = picked

            # copy code for each picked rust
            for r_key, s in picked.items():
                pair_dir = os.path.join(outdir, prob, f"pair_{pair_count}")
                os.makedirs(pair_dir, exist_ok=True)
                shutil.copy(os.path.join(c_code_dir,  f"{c_key}.c"),
                            os.path.join(pair_dir,   f"{c_key}.c"))
                shutil.copy(os.path.join(rust_code_dir, f"{r_key}.rs"),
                            os.path.join(pair_dir,     f"{r_key}.rs"))
                pair_count += 1
                total_pairs += 1

        if not summary[prob]:
            del summary[prob]

    os.makedirs(outdir, exist_ok=True)
    summary["_total_pairs"] = total_pairs
    with open(os.path.join(outdir, "pair_summary.json"), "w", encoding="utf-8") as f:
        json.dump(summary, f, indent=2, ensure_ascii=False)

    print(f"\n Done. Total pairs: {total_pairs}")
    return summary

if __name__ == "__main__":
    # code2AST(data_dir= "./Output/intermediate/second_filter", outdir= "./Output/intermediate/LEETCODE_AST")
    # dedup_dataset(
    #     data_dir="./Output/intermediate/LEETCODE_AST",
    #     outdir="./Output/intermediate/LEETCODE_DeDup",
    #     duplicate_threshold=0.80)
    filter_pairs(data_dir="./Output/intermediate/LEETCODE_DeDup",
                 outdir="./Output/LEETCODE_Data",
                 threshold=[0.85, 0.60, 0.30])