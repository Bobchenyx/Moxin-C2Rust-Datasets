import os
import json
import random
from tqdm import tqdm

# load instructions
instructions = []
base = "../scripts/instructions/function"
for instr in os.listdir(base):
    if instr.endswith(".txt"):
        with open(os.path.join(base, instr), "r", encoding="utf-8") as f:
            instructions.append(f.read())

def code2json(data_dir, output_path, seed=2025):
    random.seed(seed)
    count = 0

    with open(output_path, "w", encoding="utf-8") as out_f:
        for problem in tqdm(sorted(os.listdir(data_dir))):
            prob_path = os.path.join(data_dir, problem)
            if not os.path.isdir(prob_path):
                continue

            for pair in sorted(os.listdir(prob_path)):
                pair_path = os.path.join(prob_path, pair)
                if not os.path.isdir(pair_path):
                    continue

                c = rust = None

                for code in os.listdir(pair_path):
                    code_path = os.path.join(pair_path, code)
                    if code.endswith(".c"):
                        with open(code_path, "r", encoding="utf-8") as f:
                            c = f.read()
                    elif code.endswith(".rs"):
                        with open(code_path, "r", encoding="utf-8") as f:
                            rust = f.read()

                if c is None or rust is None:
                    continue

                temp_instruction = random.choice(instructions).strip()

                item = {
                    "dataset": "c2rust",
                    "id": f"c2rust_CodeNet_{count}",
                    "messages": [
                        {"role": "user", "content": f"{temp_instruction}\n\n{c}"},
                        {"role": "assistant", "content": rust},
                    ]
                }

                out_f.write(json.dumps(item, ensure_ascii=False) + "\n")
                count += 1

if __name__ == "__main__":
    code2json(
        data_dir="Output/CodeNet_Paired_woDup",
        output_path="Output/CodeNet.jsonl",
    )