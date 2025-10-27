impl Solution {
  pub fn unique_paths(m: i32, n: i32) -> i32 {
    let um = m as usize;
    let un = n as usize;
    let mut dp = vec![vec![0; un]; um];
    for i in 0..um {
      for j in 0..un {
        if i == 0 || j == 0 {
          dp[i][j] = 1;
          continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[um - 1][un - 1];
  }
}