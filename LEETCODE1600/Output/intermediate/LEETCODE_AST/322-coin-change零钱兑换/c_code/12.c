#define MIN(a, b) ((a) < (b) ? (a) : (b))

int dp(int* coins, int coinsSize, int amount, int *f)
{
    int min = 0xfffffff;
    int ret = 0;
    int flag = 0;
    if (amount == 0) {
        return 0;
    }
    
    for (int i = 0; i < coinsSize; ++i) {
        if (coins[i] == amount) {
            f[amount] = 1;
            return 1;
        }
        
        if (flag || coins[i] > amount) {
            continue;
        }
        
        if (f[amount - coins[i]] != 0) {
            min = MIN(min, f[amount - coins[i]]);
        } else {
            ret = dp(coins, coinsSize, amount - coins[i], f);
            if (ret == 1) {
                min = 1;
                flag = 1;
                continue;
            }
            if (ret != -1) {
                min = MIN(min, ret);
            }
        }
    }
    
    if (min != 0xfffffff) {
        f[amount] = min + 1;
        return f[amount];
    }
    return -1;
}

int coinChange(int* coins, int coinsSize, int amount){
    int *f = malloc(sizeof(int) * (amount + 1));
    
    memset(f, 0, sizeof(int) * (amount + 1));
    return dp(coins, coinsSize, amount, f);
}