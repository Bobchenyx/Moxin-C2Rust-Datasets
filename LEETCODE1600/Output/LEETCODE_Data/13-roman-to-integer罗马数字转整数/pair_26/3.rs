impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        fn roman_to_int_char(c: char) -> Option<i32> {
            match c {
                'I' => Some(1),
                'V' => Some(5),
                'X' => Some(10),
                'L' => Some(50),
                'C' => Some(100),
                'D' => Some(500),
                'M' => Some(1000),
                _ => None,
            }
        }
        
        let mut v = 0i32;
        if s.is_empty() {
            return 0;
        }
        
        s.chars().zip(s.chars().skip(1)).for_each(|(first, second)| {
            let a = roman_to_int_char(first).unwrap();
            let b = roman_to_int_char(second).unwrap();
            v += (if a < b { -1 * a} else {a});
        });
        v += roman_to_int_char(s.chars().last().unwrap()).unwrap();
        
        v
    }
}