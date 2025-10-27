impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
         use std::collections::HashMap;
         let mut check_char = HashMap::new();
         let mut left = 0;
         let mut substr_len = 0;
 
         for (place, c) in s.char_indices() {
             check_char
                 .entry(c)
                 .and_modify(|v| {
                     if *v >= left {
                         left = *v + 1
                     }
                     *v = place
                 })
                 .or_insert(place);
             if substr_len <= place - left {
                 substr_len = place - left + 1
             }
         }
         substr_len as i32
     }
}