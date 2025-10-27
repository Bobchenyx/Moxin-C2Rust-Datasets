use std::collections::HashMap;
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut start: usize = 0;
        let mut len = 0;
        let mut max_len = 0;
        let mut map: HashMap<u8, usize> = HashMap::new();
        let mut n: usize = 0;
        let mut arr = s.as_bytes();
        let arr_size = arr.len();
        if arr_size == 0 {
            return 0;
        }
        while n < arr_size {
            let e = arr[n];
            match map.get(&e) {
                Some(v) => {
                    //repeat
                    let index = *v;
                    len = n - start;
                    if len > max_len {
                        max_len = len;
                    }

                    //update index
                    start = index + 1;
                    n = start;
                    map.clear();
                    continue;
                }
                None => {
                    //not repeat
                    len = n - start + 1;
                    map.insert(e, n);
                    if len > max_len {
                        max_len = len;
                    }
                }
            }
            n += 1;
        }
        return max_len as i32;
    }
}