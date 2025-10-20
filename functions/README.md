## Collection of C Functions and Their Rust Translations. 

### 1. Methods & Data Source

Inspired by the Project CodeNet dataset, we aim to extend cross-language resources toward C-to-Rust translation, focusing on realistic, safe, and idiomatic Rust code.
While current large language models struggle to generate Rust implementations that are both semantically equivalent to C and idiomatically correct, we believe that a truly reliable C↔Rust dataset must consist of human-written and verified code.

To this end, we turned to LeetCode, one of the largest online programming platforms with numerous high-quality, community-contributed solutions. From open-source submissions, we manually collected and aligned over 400 C↔Rust function pairs as the raw dataset, ensuring both algorithmic equivalence and functional correctness through compilation and testing.

### 2. Data Structure

```
/c2rust-moxin-function-raw
├── 0001
│   ├── 0001.c
│   └── 0001.rs
├── 0002
│   ├── 0002.c
│   └── 0002.rs
├── 0003
│   ├── 0003.c
│   └── 0003.rs
...

```
