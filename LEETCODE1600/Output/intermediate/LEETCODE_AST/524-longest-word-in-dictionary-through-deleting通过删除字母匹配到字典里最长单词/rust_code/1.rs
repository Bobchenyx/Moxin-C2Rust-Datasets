use std::collections::HashMap;

impl Solution {
    pub fn find_longest_word(s: String, mut d: Vec<String>) -> String {
        if s.is_empty() || d.is_empty() {
            return "".to_string();
        }
        d.sort_by(|a,b| { // 双关键字排序
            if a.len() == b.len() {
                return a.cmp(b);
            }
            b.len().cmp(&(a.len()))
        });
        let mut hash = HashMap::new();
        for (idx, &c) in s.as_bytes().iter().enumerate() {
            hash.entry(c).or_insert(vec![]).push(idx); // 记录s中每个字符出现的位置
        }
        for ds in d {
            let mut pos = None; // pos 记录已经扫描到s的哪个位置了(单调递增)
            let mut ok = true;
            for dc in ds.as_bytes() {
                if let Some(arr) = hash.get(dc) {  // 判断当前字符是否在s中出现
                    let next = pos.map_or(0, |v| v+1); // 如果出现, 那么它在s中的下标至少是next(即pos+1)
                    match arr.binary_search(&next) {
                        Ok(idx) => {
                            pos = Some(next);
                        },
                        Err(idx) => {
                            if idx == arr.len() { // 在s[pos+1..]中已经找不到这个字符了
                                ok = false;
                                break;
                            }
                            pos = Some(arr[idx]);
                        },
                    }
                } else {
                    ok = false;
                    break;
                }
            }
            if ok {
                return ds;
            }
        }
        "".to_string()
    }
}