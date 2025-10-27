impl Solution {
    pub fn length_of_last_word(mut s: String) -> i32 {
        let mut count = 0i32;
        loop {
            let ch = s.pop();
            if None == ch { break; }
            if ch == Some(' ') && count == 0 { continue; }
            if ch == Some(' ') { break; }
            count += 1;
        }
        count
    }
}