impl Solution {
    pub fn title_to_number(s: String) -> i32 {
        let mut str_arr = s.bytes().collect::<Vec<_>>();
        let len = s.len();
        let mut res = 0i32;
        for i in 0..len {
            let tmp = str_arr[i] - 64;
            if i != (len - 1) {
                res = (res + tmp as i32) * 26;
            } else {
                res += tmp as i32;
            }
        }
        (res)
    }
}