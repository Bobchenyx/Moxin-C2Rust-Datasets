impl Solution {
    pub fn subtract_product_and_sum(n: i32) -> i32 {
        let mut num = n;
        let mut pro = 1i32;
        let mut sum = 0i32;

        while 0 != num {
            let temp = num % 10;
            pro *= temp;
            sum += temp;
            num /= 10;
        }

        (pro - sum)
    }
}