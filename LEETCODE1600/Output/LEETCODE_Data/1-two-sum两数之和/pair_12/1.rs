rust []
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        
        let l = nums.len();
        
        let mut a = vec![0; l];
        
        for i in 0..l {
            
            for i1 in 0..i {
                
                if nums[i] == a[i1] {
                    
                    let result = vec![i1 as i32, i as i32];
                    
                    return result;
                }
            }
            
            a[i] = target - nums[i];
        }
        [0,0].to_vec()
    }
}