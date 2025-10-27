impl Solution {
    pub fn prefixes_div_by5(a: Vec<i32>) -> Vec<bool> {
        let mut result = Vec::with_capacity(a.len());
        let mut n = 0;

        for i in a {
            n <<= 1;
            n += i;
            result.push(n % 5 == 0);
            n %= 5;
        }
        result
    }
}