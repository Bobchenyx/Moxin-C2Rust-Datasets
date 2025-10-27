impl Solution {
    pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32> {
        let mut v = vec![-1;100];
        for (&n, &i) in nums.iter().zip(&index) {
            let i = i as usize;
            v.copy_within(i..99, i+1);
            v[i] = n;
        }
        v.retain(|&x| x != -1);
        v
    }
}