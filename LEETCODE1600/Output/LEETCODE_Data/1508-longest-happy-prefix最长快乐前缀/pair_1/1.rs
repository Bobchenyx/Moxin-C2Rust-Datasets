impl Solution {
    pub fn longest_prefix(s: String) -> String {
        let  s_bytes = s.as_bytes();
        for i in 1..s.len() {
            if s.get(0..(s.len() - i)) == s.get(i..s.len()){
                return String::from(s.get(i..s.len()).unwrap());
            }
        }
        String::from("")
    }
    
}