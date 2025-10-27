impl Solution {
    pub fn check_perfect_number(num: i32) -> bool {
        if num % 10 != 6 && num % 10 != 8 { return false; }
        let mut sum = 1;
        let mut left = 2;
        let mut right = num;
        while left < right {
            if num % left == 0 {
                right = num / left;
                sum += left;
                sum += right;
            }
            left += 1;
        }
        sum == num 
    }
}