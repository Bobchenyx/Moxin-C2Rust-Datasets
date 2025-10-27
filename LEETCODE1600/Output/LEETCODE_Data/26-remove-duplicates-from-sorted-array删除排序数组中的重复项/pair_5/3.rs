impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let len = nums.len();
        if len<2{
            return len as i32;
        }

        let mut i = 0;
      
        for j in 1..len{
            if nums[j]>nums[i]{
                i+=1;
                if i!=j{
                    nums[i] = nums[j];
                }
            }
        }

        (i+1) as i32
    }
}