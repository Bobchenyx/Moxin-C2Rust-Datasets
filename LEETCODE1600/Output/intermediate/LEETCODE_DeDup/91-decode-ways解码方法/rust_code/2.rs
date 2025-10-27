impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        let lq26 = |f, l| (f - b'0') * 10 + (l - b'0') <= 26;
        let s = s.as_bytes();
        if s[0] == b'0' {
            return 0;
        }
        let mut fn_1 = 1;
        let mut fn_2 = 1;
        for i in 1..s.len() {
            let mut tmp = 0;
            if s[i] == b'0' && (s[i-1] == b'0' || s[i - 1] >= b'3') {
                return 0;
            } 
            if s[i] == b'0' {
                tmp = fn_2;
            } else {
                tmp = fn_1 + if lq26(s[i - 1], s[i]) && s[i - 1] != b'0' { fn_2 } else { 0 };
            }
            
            fn_2 = fn_1;
            fn_1 = tmp;
        }
        fn_1
    }
}