impl Solution {
    pub fn replace_spaces(s: String, length: i32) -> String {
        let mut res: String = String::from("");
        for (index, v) in s.chars().enumerate(){
            if index as i32 == length {break}
            match v {
                ' ' => {res += "%20"},
                _ => {res += &(v.to_string())}
            }
        }
        res
    }
}