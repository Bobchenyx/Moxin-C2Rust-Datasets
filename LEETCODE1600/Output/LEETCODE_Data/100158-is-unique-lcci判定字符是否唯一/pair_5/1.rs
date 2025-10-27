//code style is bad
impl Solution {
    pub fn is_unique(astr: String) -> bool {
        let cs = astr.chars();
        let mut count = vec![0; ('z' as i32 as usize) + 1];//123
        for c in cs {
            count[(c as i32) as usize] += 1;
        }
        for &c in count.iter() {
            if c > 1 {
                return false;
            }
        }
        true
    }
}