use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len <= 1 {
            return len as i32;
        }
        let mut st = HashSet::new();
        for x in nums {
            st.insert(x);
        }
        let mut longest = 0;
        for x in st.iter() {
            if st.contains(&(x - 1)) == false {
                let mut cur = x + 1;
                let mut local_longest = 1;
                while st.contains(&cur) {
                    cur += 1;
                    local_longest += 1;
                }
                longest = std::cmp::max(longest, local_longest);
            }
        }
        longest
    }
}