impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;
        for i in (0..digits.len()).rev() {
            digits[i] += 1;
            digits[i] %= 10;
            if digits[i] != 0 {
                return digits;
            }
        }
        let mut res = vec![1];
        res.append(&mut digits);
        res
    }
}