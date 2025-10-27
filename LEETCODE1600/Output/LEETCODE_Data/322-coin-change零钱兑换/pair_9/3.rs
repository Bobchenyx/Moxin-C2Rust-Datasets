impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        // dp[m]: minimum number of coins to reach amount value
        // dp[m] = min(dp[m - coins[i]] + 1, dp[m])
        // initilize d[[coins[i]]] = 1;
        if amount == 0 {
            return 0;
        }
        let mut dp = vec![amount + 1; amount as usize + 1];
        dp[0] = 0;

        for i in 0..coins.len() {
            for m in coins[i]..amount+1 {
                dp[m as usize] = dp[m as usize].min(dp[(m - coins[i]) as usize] + 1);
            }
        }

        let res = if dp[amount as usize] > amount {-1} else {dp[amount as usize]};
        res
    }
}