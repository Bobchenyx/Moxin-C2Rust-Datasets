impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        let mut count = 0i32;
        let mut l_flag = 0i32;
        let mut r_flag = 0i32;

        for c in s.chars() {
            match c {
                'L' => l_flag += 1,
                'R' => r_flag += 1,
                _ => return -1,
            }

            if l_flag == r_flag {
                count += 1;
                l_flag = 0;
                r_flag = 0;
            }
        }

        (count)
    }
}