use std::collections::HashSet;
impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut set: HashSet<i32> = HashSet::new();
        for item in nums1 {
            if nums2.contains(&item) {
                set.insert(item);
            }
        }
        let mut ans: Vec<i32> = Vec::new();
        for item in set {
            ans.push(item);
        }
        (ans)
    }
}