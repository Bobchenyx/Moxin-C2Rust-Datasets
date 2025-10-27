impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut res = nums[0];

        for i in nums {
            if sum > 0 {
                sum += i;
            } else {
                sum = i;
            }
            res = std::cmp::max(res, sum);
        }
        res
    }
}