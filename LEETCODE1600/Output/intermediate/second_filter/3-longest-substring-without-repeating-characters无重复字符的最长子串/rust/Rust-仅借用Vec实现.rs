impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut v: Vec<u8> = Vec::new();
        let mut count = 0;
        for i in s.bytes() {
            if v.contains(&i) {
                if v.len() >= count {
                    count = v.len();
                }
                while (v.contains(&i)) {
                    v.remove(0);
                }
                v.push(i);
            } else {
                v.push(i);
                if v.len() >= count {
                    count = v.len();
                }
            }
        }
        count as i32
    }
}