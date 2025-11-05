# #!/usr/bin/env python3
# # -*- coding: utf-8 -*-
#
# import argparse
# import os
# from pathlib import Path
#
# def strip_impl_solution_blocks(src: str) -> tuple[str, int]:
#     """
#     在源码中删除所有 `impl Solution { ... }` 外壳，保留内部内容。
#     采用字符级扫描，忽略字符串/字符字面量、注释中的花括号。
#     返回 (新源码, 删除的 block 数)
#     """
#     s = src
#     i = 0
#     n = len(s)
#     out = []
#     removed = 0
#
#     # 状态机
#     in_line_comment = False
#     in_block_comment = False
#     in_str = False
#     in_char = False
#     esc = False
#
#     def peek(k: int) -> str:
#         return s[k] if 0 <= k < n else ""
#
#     while i < n:
#         ch = s[i]
#
#         # 处理状态退出
#         if in_line_comment:
#             out.append(ch)
#             if ch == "\n":
#                 in_line_comment = False
#             i += 1
#             continue
#         if in_block_comment:
#             out.append(ch)
#             if ch == "*" and peek(i + 1) == "/":
#                 out.append("/")
#                 i += 2
#                 in_block_comment = False
#             else:
#                 i += 1
#             continue
#         if in_str:
#             out.append(ch)
#             if esc:
#                 esc = False
#             else:
#                 if ch == "\\":
#                     esc = True
#                 elif ch == '"':
#                     in_str = False
#             i += 1
#             continue
#         if in_char:
#             out.append(ch)
#             if esc:
#                 esc = False
#             else:
#                 if ch == "\\":
#                     esc = True
#                 elif ch == "'":
#                     in_char = False
#             i += 1
#             continue
#
#         # 进入注释/字符串/字符字面量
#         if ch == "/" and peek(i + 1) == "/":
#             out.append("//")
#             i += 2
#             in_line_comment = True
#             continue
#         if ch == "/" and peek(i + 1) == "*":
#             out.append("/*")
#             i += 2
#             in_block_comment = True
#             continue
#         if ch == '"':
#             out.append(ch)
#             in_str = True
#             i += 1
#             continue
#         if ch == "'":
#             out.append(ch)
#             in_char = True
#             i += 1
#             continue
#
#         # 尝试匹配 "impl Solution"（允许后续有泛型/空白/注释，直到遇到 '{'）
#         if s.startswith("impl Solution", i):
#             j = i + len("impl Solution")
#             # 跳过空白/注释，直到找到 '{'
#             depth_scan = j
#             # 临时状态用于扫描到 '{'
#             _in_line = False
#             _in_block = False
#             found_brace = -1
#
#             while depth_scan < n:
#                 c = s[depth_scan]
#                 d = peek(depth_scan + 1)
#
#                 if _in_line:
#                     if c == "\n":
#                         _in_line = False
#                     depth_scan += 1
#                     continue
#                 if _in_block:
#                     if c == "*" and d == "/":
#                         depth_scan += 2
#                         _in_block = False
#                     else:
#                         depth_scan += 1
#                     continue
#
#                 if c.isspace():
#                     depth_scan += 1
#                     continue
#                 if c == "/" and d == "/":
#                     _in_line = True
#                     depth_scan += 2
#                     continue
#                 if c == "/" and d == "*":
#                     _in_block = True
#                     depth_scan += 2
#                     continue
#                 if c == "{":
#                     found_brace = depth_scan
#                     break
#                 # 允许泛型/where子句/生命周期等内容，继续扫
#                 depth_scan += 1
#
#             if found_brace == -1:
#                 # 没有 '{'，当普通文本
#                 out.append(ch)
#                 i += 1
#                 continue
#
#             # 从 found_brace 开始做大括号匹配，提取块内容
#             k = found_brace
#             depth = 0
#
#             # 再次使用严格状态机，避免字符串/注释中的花括号干扰
#             ss_in_line = False
#             ss_in_block = False
#             ss_in_str = False
#             ss_in_char = False
#             ss_esc = False
#
#             block_start = k
#             k += 1
#             depth = 1
#             while k < n and depth > 0:
#                 c = s[k]
#                 d = peek(k + 1)
#
#                 if ss_in_line:
#                     if c == "\n":
#                         ss_in_line = False
#                     k += 1
#                     continue
#                 if ss_in_block:
#                     if c == "*" and d == "/":
#                         k += 2
#                         ss_in_block = False
#                     else:
#                         k += 1
#                     continue
#                 if ss_in_str:
#                     if ss_esc:
#                         ss_esc = False
#                     else:
#                         if c == "\\":
#                             ss_esc = True
#                         elif c == '"':
#                             ss_in_str = False
#                     k += 1
#                     continue
#                 if ss_in_char:
#                     if ss_esc:
#                         ss_esc = False
#                     else:
#                         if c == "\\":
#                             ss_esc = True
#                         elif c == "'":
#                             ss_in_char = False
#                     k += 1
#                     continue
#
#                 # 进入注释/字符串
#                 if c == "/" and d == "/":
#                     ss_in_line = True
#                     k += 2
#                     continue
#                 if c == "/" and d == "*":
#                     ss_in_block = True
#                     k += 2
#                     continue
#                 if c == '"':
#                     ss_in_str = True
#                     k += 1
#                     continue
#                 if c == "'":
#                     ss_in_char = True
#                     k += 1
#                     continue
#
#                 if c == "{":
#                     depth += 1
#                     k += 1
#                     continue
#                 if c == "}":
#                     depth -= 1
#                     k += 1
#                     continue
#
#                 k += 1
#
#             if depth != 0:
#                 # 不完整的大括号，按普通文本处理
#                 out.append(ch)
#                 i += 1
#                 continue
#
#             # block 内容是 (found_brace+1 .. k-1)
#             inner = s[found_brace + 1 : k - 1]
#
#             # 把 i..k 这段整体替换为 inner
#             out.append(inner)
#             removed += 1
#             i = k
#             continue
#
#         # 常规字符
#         out.append(ch)
#         i += 1
#
#     new_src = "".join(out)
#
#     # 清理多余的空行（可选，尽量温和）
#     # 连续 3+ 行空行压成 2 行
#     lines = new_src.splitlines(True)
#     cleaned = []
#     blank_run = 0
#     for ln in lines:
#         if ln.strip() == "":
#             blank_run += 1
#             if blank_run <= 2:
#                 cleaned.append(ln)
#         else:
#             blank_run = 0
#             cleaned.append(ln)
#
#     return ("".join(cleaned), removed)
#
# def process_file(path: Path, dry_run: bool, verbose: bool) -> int:
#     src = path.read_text(encoding="utf-8", errors="ignore")
#     new_src, removed = strip_impl_solution_blocks(src)
#     if removed > 0 and new_src != src:
#         if verbose:
#             print(f"[MOD] {path}  (removed {removed} block{'s' if removed > 1 else ''})")
#         if not dry_run:
#             path.write_text(new_src, encoding="utf-8")
#     elif verbose:
#         print(f"[SKIP] {path}  (no impl Solution block)")
#     return removed
#
# def main():
#     ap = argparse.ArgumentParser(description="递归删除所有 .rs 文件中的 `impl Solution { ... }` 外壳。")
#     ap.add_argument("root", help="根目录")
#     ap.add_argument("--dry-run", action="store_true", help="预览模式，不落盘写回")
#     ap.add_argument("--verbose", action="store_true", help="输出每个文件的处理结果")
#     args = ap.parse_args()
#
#     root = Path(args.root).resolve()
#     if not root.exists() or not root.is_dir():
#         raise SystemExit(f"根目录不存在或不是目录: {root}")
#
#     total_files = 0
#     total_removed = 0
#     for dirpath, _, filenames in os.walk(root):
#         for fn in filenames:
#             if fn.endswith(".rs"):
#                 total_files += 1
#                 p = Path(dirpath) / fn
#                 total_removed += process_file(p, args.dry_run, args.verbose)
#
#     print(f"\nDone. Scanned {total_files} .rs files, removed {total_removed} impl block(s).")
#     if args.dry_run:
#         print("(dry-run: 未写回修改)")
#
# if __name__ == "__main__":
#     main()

#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import argparse
import os
from pathlib import Path
import textwrap


def dedent_block(text: str) -> str:
    """去掉块内容中最小统一缩进"""
    lines = text.splitlines()
    # 只统计非空行的前导空格
    indents = []
    for ln in lines:
        if ln.strip():
            spaces = len(ln) - len(ln.lstrip(" "))
            indents.append(spaces)
    if not indents:
        return text
    min_indent = min(indents)
    if min_indent == 0:
        return text
    return "\n".join(ln[min_indent:] if len(ln) >= min_indent else ln for ln in lines)


def strip_impl_solution_blocks(src: str) -> tuple[str, int]:
    """
    删除 `impl Solution { ... }` 外壳并去除内部统一缩进。
    返回: (新源码, 删除的 block 数)
    """
    s = src
    n = len(s)
    i = 0
    out = []
    removed = 0

    while i < n:
        if s.startswith("impl Solution", i):
            j = i + len("impl Solution")
            # 向前扫描找到第一个 '{'
            while j < n and s[j] != "{":
                j += 1
            if j >= n:
                out.append(s[i])
                i += 1
                continue
            # 匹配花括号块
            depth = 1
            k = j + 1
            while k < n and depth > 0:
                if s[k] == "{":
                    depth += 1
                elif s[k] == "}":
                    depth -= 1
                k += 1
            if depth != 0:
                out.append(s[i])
                i += 1
                continue
            inner = s[j + 1 : k - 1]
            dedented = dedent_block(inner)
            out.append(dedented)
            removed += 1
            i = k
        else:
            out.append(s[i])
            i += 1

    new_src = "".join(out)
    # 简单清理连续空行
    lines = new_src.splitlines(True)
    cleaned = []
    blank_run = 0
    for ln in lines:
        if ln.strip() == "":
            blank_run += 1
            if blank_run <= 2:
                cleaned.append(ln)
        else:
            blank_run = 0
            cleaned.append(ln)
    return ("".join(cleaned), removed)


def process_file(path: Path, dry_run: bool, verbose: bool) -> int:
    src = path.read_text(encoding="utf-8", errors="ignore")
    new_src, removed = strip_impl_solution_blocks(src)
    if removed > 0 and new_src != src:
        if verbose:
            print(f"[MOD] {path}  (removed {removed} block{'s' if removed > 1 else ''})")
        if not dry_run:
            path.write_text(new_src, encoding="utf-8")
    elif verbose:
        print(f"[SKIP] {path}")
    return removed


def main():
    ap = argparse.ArgumentParser(description="递归删除所有 .rs 文件中的 `impl Solution { ... }` 外壳并去缩进。")
    ap.add_argument("root", help="根目录路径")
    ap.add_argument("--dry-run", action="store_true", help="仅预览，不写回文件")
    ap.add_argument("--verbose", action="store_true", help="显示详细输出")
    args = ap.parse_args()

    root = Path(args.root).resolve()
    if not root.exists() or not root.is_dir():
        raise SystemExit(f"根目录不存在或不是目录: {root}")

    total_files = 0
    total_removed = 0
    for dirpath, _, filenames in os.walk(root):
        for fn in filenames:
            if fn.endswith(".rs"):
                total_files += 1
                fpath = Path(dirpath) / fn
                total_removed += process_file(fpath, args.dry_run, args.verbose)

    print(f"\n✅ Done. Processed {total_files} .rs files, removed {total_removed} impl block(s).")
    if args.dry_run:
        print("(dry-run: 未写回修改)")


if __name__ == "__main__":
    main()