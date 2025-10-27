use std::mem;

impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        match nums.len() {
            0 => 0,
            _ => {
                let mut max = i32::min_value();
                let mut curr_min = 1;
                let mut curr_max = 1;
                for n in nums.into_iter() {
                    if n < 0 {
                        mem::swap(&mut curr_max, &mut curr_min);
                    }
                    curr_max = n.max(curr_max * n);
                    curr_min = n.min(curr_min * n);
                    max = max.max(curr_max);
                }
                max
            }
        }
    }
}