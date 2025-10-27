rust []
impl Solution {
    pub fn sum_nums(n: i32) -> i32 {
        (1..(n + 1)).fold(0, |sum, x| sum + x)
    }
}