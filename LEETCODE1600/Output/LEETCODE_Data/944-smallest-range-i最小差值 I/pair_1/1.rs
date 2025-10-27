impl Solution {
    pub fn smallest_range_i(a: Vec<i32>, k: i32) -> i32 {
        let x = a.iter().max().unwrap();
        let y = a.iter().min().unwrap();
        let ans = x - y - 2 * k;
        if ans <= 0 { // 小于0必然有0为最小差值
            return 0;
        } else {
            return ans;
        }
    }
}