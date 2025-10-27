impl Solution {
    pub fn transpose(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = vec![vec![0; a.len()]; a[0].len()];
        for i in 0..a[0].len() {
            for j in 0..a.len() {
                ans[i][j] = a[j][i];
            }
        }
        (ans)
    }
}