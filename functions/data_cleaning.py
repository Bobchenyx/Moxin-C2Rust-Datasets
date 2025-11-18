import os
import shutil
import re
from collections import defaultdict

def first_filter(source, output):
    """
    First filter, given source data, fetch and store c and rs files only.
    """
    for q in os.listdir(source):
        q_path = os.path.join(source, q)
        if os.path.isdir(q_path):
            for folder in os.listdir(q_path):
                folder_path = os.path.join(q_path, folder)
                if os.path.isdir(folder_path):
                    c_dir = os.path.join(folder_path, "c")
                    rust_dir = os.path.join(folder_path, "rust")
                    
                    if (os.path.isdir(c_dir) and os.path.isdir(rust_dir) and 
                        len(os.listdir(c_dir)) > 0 and len(os.listdir(rust_dir)) > 0):
                        
                        output_folder = os.path.join(output, q, folder)
                        
                        # Copy both directories
                        shutil.copytree(c_dir, os.path.join(output_folder, "c"), dirs_exist_ok=True)
                        shutil.copytree(rust_dir, os.path.join(output_folder, "rust"), dirs_exist_ok=True)
                        
                        print(f"Copied: {q}/{folder}")


def second_filter(output):
    """
    Second filter: for each code file, get rid off the text blocks and keep codes only
    """
    source = "Output/intermediate/first_filter"
    
    # Get the code block
    code_block_pattern = r'```(?:\w*\n)?(.*?)```'
    
    # Dict for summary
    folder_stats = defaultdict(lambda: {"c": 0, "rust": 0})
    
    for root, dirs, files in os.walk(source):
        for file in files:
            file_path = os.path.join(root, file)
            
            try:
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                
                # Find all code blocks
                matches = re.findall(code_block_pattern, content, re.DOTALL)
                
                if matches:
                    # Determine extension based on directory structure
                    if 'c' in os.path.basename(root):
                        ext = '.c'
                        file_type = 'c'
                    elif 'rust' in os.path.basename(root):
                        ext = '.rs'
                        file_type = 'rust'
                    else:
                        continue
                    # Take the first code block
                    code = matches[0].strip()
                    
                    # Parse the path structure: question/intermediate/c (or rust)
                    relative_path = os.path.relpath(root, source)
                    path_parts = relative_path.split(os.sep)
                    
                    # Get question name and lang
                    question = path_parts[0]
                    lang_folder = os.path.basename(root)  # 'c' or 'rust'
                    
                    output_dir = os.path.join(output, question, lang_folder)
                    os.makedirs(output_dir, exist_ok=True)
                    
                    # Generate output filename
                    base_name = os.path.splitext(file)[0]
                    output_file = f"{base_name}{ext}"
                    output_path = os.path.join(output_dir, output_file)
                    
                    # Write the extracted code
                    with open(output_path, 'w', encoding='utf-8') as f:
                        f.write(code)
                    
                    # Update statistics
                    folder_stats[question][file_type] += 1
                    
                    print(f"Extracted: {question}/{lang_folder}/{output_file}")
                    
            except Exception as e:
                print(f"Error processing {file_path}: {e}")
    
    # summary
    summary_file = os.path.join(output, "summary.txt")
    
    total_c = sum(stats["c"] for stats in folder_stats.values())
    total_rust = sum(stats["rust"] for stats in folder_stats.values())
    total_questions = len(folder_stats)
    
    with open(summary_file, 'w') as f:
        f.write("=" * 70 + "\n")
        f.write("TOTAL SUMMARY\n")
        f.write("=" * 70 + "\n")
        f.write(f"Total Questions: {total_questions}\n")
        f.write(f"Total C Files: {total_c}\n")
        f.write(f"Total Rust Files: {total_rust}\n")
        f.write(f"Total Files: {total_c + total_rust}\n")
        f.write("=" * 70 + "\n\n")
        
        f.write(f"{'Question':<50} {'C Files':>10} {'Rust Files':>10}\n")
        f.write("-" * 70 + "\n")
        
        for question in sorted(folder_stats.keys()):
            stats = folder_stats[question]
            if stats["c"] > 0 or stats["rust"] > 0:
                f.write(f"{question:<50} {stats['c']:>10} {stats['rust']:>10}\n")
        
        f.write("-" * 70 + "\n")
        f.write(f"{'TOTAL':<50} {total_c:>10} {total_rust:>10}\n")
    
    print("\n" + "=" * 70)
    print(f"EXTRACTION COMPLETE - Summary saved to: {summary_file}")
    print("=" * 70)
    print(f"Total Questions: {total_questions}")
    print(f"Total C Files: {total_c}")
    print(f"Total Rust Files: {total_rust}")
    print(f"Total Files: {total_c + total_rust}")
    print("=" * 70)

if __name__ == "__main__":
    first_filter("./leetcode", "./Output/intermediate/first_filter")
    second_filter("./Output/intermediate/second_filter")