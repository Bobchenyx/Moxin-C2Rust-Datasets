# Moxin-C2Rust-Datasets
Moxin's Collection of c2rus datasets, survey &amp; tech report

[![arXiv](https://img.shields.io/badge/arXiv-2509.25689-df2a2a?logo=arxiv&logoColor=white)](https://www.arxiv.org/abs/2509.25689)
[![HuggingFace](https://img.shields.io/badge/HuggingFace-Moxin-FFD21F?logo=huggingface&logoColor=yellow)](https://huggingface.co/moxin-org)
[![c2rust](https://img.shields.io/badge/c2rust-Reference-0078D7?labelColor=555555&logoColor=white)](https://github.com/immunant/c2rust)

## Introduction
C2Rust-Moxin is a large-scale paired dataset designed for learning, evaluating, and benchmarking C-to-Rust code translation.
The dataset provides aligned source files between C and Rust programs collected from diverse open-source projects, enabling fine-grained study on syntax conversion, semantic preservation, and idiomatic rewriting from low-level imperative C code to safe and expressive Rust code.

## Dataset Overview
For each component of this project, we provide detailed usage instructions and examples in the corresponding subfolder README files.  

- [`functions/`](./functions/) — Function-level C↔Rust pairs, aligned one-to-one for fine-grained translation, semantic equivalence, and syntax-level modeling.
- [`programs/`](./programs/) — Program-level (CLI or small app) correspondences, enabling evaluation of end-to-end translation and compilation consistency.
- [`projects/`](./projects/) — Project-level C↔Rust mappings, supporting large-scale cross-language migration and structural analysis across complete codebases.
- [`scripts/`](./scripts/) — Provides data preprocessing, filtering, and SFT instruction generation scripts used throughout the dataset construction pipeline.



---
## Citation

If this work is helpful, please kindly cite as:

```bibtex
@article{chen2025collaborative,
  title={Collaborative Compression for Large-Scale MoE Deployment on Edge},
  author={Chen, Yixiao and Xie, Yanyue and Yang, Ruining and Jiang, Wei and Wang, Wei and He, Yong and Chen, Yue and Zhao, Pu and Wang, Yanzhi},
  journal={arXiv preprint arXiv:2509.25689},
  year={2025}
}
```

## Acknowledgements

This repository builds upon the outstanding work of the following open-source authors and projects:

- [c2rust](https://github.com/immunant/c2rust).
- [Project_CodeNet](https://github.com/IBM/Project_CodeNet).
- [sactor](https://github.com/qsdrqs/sactor).
- [leetcode](https://leetcode.com/problemset/), [leetcode_CN](https://leetcode.cn/problemset/).


We sincerely thank them for their excellent contributions to the open-source community.
