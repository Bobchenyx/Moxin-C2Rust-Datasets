impl Solution {
    pub fn replace_elements(arr: Vec<i32>) -> Vec<i32> {
        let mut ans = arr;
        let len = ans.len();
        let mut rmax = ans[len - 1];
        ans[len - 1] = -1;

        for i in 2..(len + 1) {
            let temp = ans[len - i]; // 从右向左遍历
            ans[len - i] = rmax;
            if temp > rmax {
                rmax = temp;
            }
        }

        (ans)
    }
}