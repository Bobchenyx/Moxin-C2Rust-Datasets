use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut res = vec![];
        let mut cache = HashMap::new();

        for (index, item) in nums.iter().enumerate() {
            let sub = target - *item;

            match cache.get(item) {
                Some(pre_index) => {
                    res.push(*pre_index);
                    res.push(index as i32);
                    return res
                },
                None => {
                    cache.insert(sub, index as i32);
                },
            }
        }
        res
    }
}