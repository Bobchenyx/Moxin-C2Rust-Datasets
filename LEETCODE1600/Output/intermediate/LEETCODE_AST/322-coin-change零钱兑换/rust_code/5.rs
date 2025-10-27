impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let amount= amount as usize;
        let len = amount + 1;
        let coin_types:Vec<usize> = coins.iter().map(|v| *v as usize).collect();
        let mut dp:Vec<i32> = vec![-1;len];
        dp[0] = 0;
        for &coin in coin_types.iter(){
            for i in coin..len{
                 dp[i] = match (dp[i - coin] == -1,dp[i] == -1){
                     (true,_) => dp[i],
                     (false,true) => dp[i - coin] + 1,
                     _ => dp[i].min(dp[i-coin] + 1),
                 }
            }
        }
        dp[amount]
    }
}