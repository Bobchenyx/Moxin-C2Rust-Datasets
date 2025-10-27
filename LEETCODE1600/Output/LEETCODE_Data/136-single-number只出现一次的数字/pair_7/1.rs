pub fn single_number(nums: Vec<i32>) -> i32 {
    let mut count = 0;
    for n in nums.iter(){
        count = count ^ *n;
    }
    count
}