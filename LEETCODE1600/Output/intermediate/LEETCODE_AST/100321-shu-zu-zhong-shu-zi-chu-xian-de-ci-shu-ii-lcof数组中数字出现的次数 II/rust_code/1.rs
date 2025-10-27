impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        // ab ab ab ab
        // 00 01 11 00
        let mut a = 0;
        let mut b = 0;
        for n in nums {
            let t = a;
            a = (n & !a & b) + (!n & a);
            b = (n & !t) + (!n & b);
            // println!("{:?}", (n, a, b));
        }
        b
    }
}