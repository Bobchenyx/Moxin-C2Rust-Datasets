impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
    if nums.len()<=1{
        return;
    }
    let mut max = i32::min_value();
    let mut len = nums.len();
    if nums[len -1] > nums[len -2]{
        nums.swap(len -1, len -2)
    }
    else {
        let mut index = len - 2;
        let mut i = 0;
        let mut is_break = false;
        while index > 0{
            if nums[index] > nums[index-1]{
                let mut min = index;
                for j in index..len{
                    if nums[j] > nums[index-1] && nums[j] < nums[min]{
                        min = j
                    }
                }
                nums.swap(index -1, min);
                nums[index..len].sort();
                is_break = true;
                break
            }
            else {
                index = index - 1
            }
        }
        if is_break == false{
            nums.sort();
        }
    }
}
}