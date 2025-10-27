use std::collections::HashSet;
impl Solution {
    pub fn minimum_length_encoding(words: Vec<String>) -> i32 {
        let mut words_re :Vec<String>= words.clone().into_iter().map(|w| w.chars().rev().collect::<String>()).collect();
        words_re.sort();
        let mut ans = 0;
        (1..words_re.len()).for_each(|i| {
            let word:&String = &words_re[i];
            let pre :&String = &words_re[i-1];
            if !word.starts_with(pre) {
                ans += &words_re[i-1].len() + 1;
            }
        });
        ans += words_re.last().unwrap().len() + 1;
        ans as i32
    }
}