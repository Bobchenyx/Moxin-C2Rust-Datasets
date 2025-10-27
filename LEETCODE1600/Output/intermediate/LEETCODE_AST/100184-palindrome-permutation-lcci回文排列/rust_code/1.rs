use std::collections::HashMap;

impl Solution {
    pub fn can_permute_palindrome(s: String) -> bool {
        if s.len() == 1 {
            return true
        }
        let mut res_map = HashMap::with_capacity(s.len());
        for v in s.chars(){
            let count = res_map.entry(v).or_insert(0);
            *count += 1
        }
        println!("map = {:?}", res_map);
        let mut odd = 0;
        for (k, v) in res_map {
            if v % 2 != 0 {
                odd += 1
            }
            if odd > 1 {
                return false
            }
        }
        return true
    }
}