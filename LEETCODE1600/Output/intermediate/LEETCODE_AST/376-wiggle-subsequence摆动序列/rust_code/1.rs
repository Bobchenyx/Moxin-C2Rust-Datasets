impl Solution {
  pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
    let len = nums.len();
    if len < 2 {
      return len as i32;
    }

    let mut down = 1;
    let mut up = 1;

    for i in 1..len {
      if nums[i] > nums[i - 1] {
        up = std::cmp::max(down + 1, up);
      } else if nums[i] < nums[i - 1] {
        down = std::cmp::max(up + 1, down);
      }
    }

    std::cmp::max(down, up)
  }