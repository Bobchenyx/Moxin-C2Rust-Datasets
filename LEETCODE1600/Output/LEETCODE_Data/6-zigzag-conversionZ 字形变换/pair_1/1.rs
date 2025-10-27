impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let len = s.len();
        if len < 2 || num_rows == 1 {
            return s;
        }
        let s = s.as_bytes();
        let mut buf = Vec::with_capacity(len);
        let period = num_rows as usize - 1;
        let rest = {
            let rem = len % (period * 2);
            if rem == 0 {
                period - 1
            } else if rem > period + 1 {
                rem - period - 1
            } else {
                0
            }
        };
        for j in 0..=period {
            for i in (0..len).step_by(period * 2) {
                if j != 0 && i >= j && j != period {
                    buf.push(s[i - j]);
                }
                if let Some(&b) = s.get(i + j) {
                    buf.push(b);
                }
            }
            if rest != 0 && period - j <= rest && j != period {
                buf.push(s[len - rest + period - j - 1])
            }
        }
        unsafe { String::from_utf8_unchecked(buf) }
    }
}