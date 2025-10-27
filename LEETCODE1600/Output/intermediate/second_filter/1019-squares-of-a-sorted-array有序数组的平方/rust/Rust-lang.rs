impl Solution {
    pub fn sorted_squares(a: Vec<i32>) -> Vec<i32> {
        let mut ans: Vec<i32> = a;
        
        for item in &mut ans {
            *item = item.pow(2); // 平方
        }
        ans.sort(); // 排序

        (ans)
    }
}