impl Solution {
    pub fn count_eval(s: String, result: i32) -> i32 {
        let str = Vec::from(s.as_str());
        let len = str.len();
        // dp[i][j].0 means the count of combination with result 0 in range [i,j]
        // i here in str index is i * 2 for oprand, i * 2 + 1 for operator
        let mut dp = vec![vec![(0, 0); len / 2 + 1]; len / 2 + 1];

        for diff in 0..(len / 2 + 1) {
            let mut start = 0;
            while start + diff < len / 2 + 1 {
                let end = start + diff;
                if diff == 0 {
                    if str[start * 2] == '1' as u8 {
                        dp[start][start].1 = 1;
                    } else {
                        dp[start][start].0 = 1;
                    }
                } else {
                    for i in start..end {
                        let op = str[i * 2 + 1] as char;
                        match op {
                            '&' => {
                                dp[start][end].0 += dp[start][i].1 * dp[i + 1][end].0
                                    + dp[start][i].0 * dp[i + 1][end].0
                                    + dp[start][i].0 * dp[i + 1][end].1;
                                dp[start][end].1 += dp[start][i].1 * dp[i + 1][end].1;
                            }
                            '|' => {
                                dp[start][end].1 += dp[start][i].1 * dp[i + 1][end].0
                                    + dp[start][i].1 * dp[i + 1][end].1
                                    + dp[start][i].0 * dp[i + 1][end].1;
                                dp[start][end].0 += dp[start][i].0 * dp[i + 1][end].0;
                            }
                            '^' => {
                                dp[start][end].0 += dp[start][i].0 * dp[i + 1][end].0
                                    + dp[start][i].1 * dp[i + 1][end].1;
                                dp[start][end].1 += dp[start][i].0 * dp[i + 1][end].1
                                    + dp[start][i].1 * dp[i + 1][end].0;
                            }
                            _ => {}
                        }
                    }
                }
                start += 1;
            }
        }
        
        return if result == 1 {
            dp[0][len / 2].1
        } else {
            dp[0][len / 2].0
        }
    }
}