impl Solution {
    pub fn min_moves2(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut min_moves = 0;
        for n in nums.iter() {
            min_moves += (nums[nums.len() / 2] - n).abs();
        }
        min_moves
    }
}