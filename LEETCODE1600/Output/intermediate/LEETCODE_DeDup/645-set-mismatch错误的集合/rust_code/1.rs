use std::collections::HashSet;
impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let length = nums.len() as i32;
        let mut set:HashSet<i32> = HashSet::new();
        let mut extra = 0;
        let mut sum = 0;
        for i in nums {
            if set.contains(&i) {
                extra = i;
            } else {
                set.insert(i);
            }
            sum += i;
        }
        let std = (length * length + length) / 2;
        let lost = std - sum + extra;
        return vec![extra,lost];
    }
}