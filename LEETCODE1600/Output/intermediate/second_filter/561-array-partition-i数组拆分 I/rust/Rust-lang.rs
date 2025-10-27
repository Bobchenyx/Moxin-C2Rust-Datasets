impl Solution {
    pub fn array_pair_sum(nums: Vec<i32>) -> i32 {
        let mut numbers = nums;
        let mut sum = 0i32;
        let mut index = 0usize;
        numbers.sort(); // 排序
        loop {
            sum += numbers[index]; // 偶数位数求和，从0开始
            index += 2;
            if index == numbers.len() {
                break;
            }
        }
        (sum)
    }
}