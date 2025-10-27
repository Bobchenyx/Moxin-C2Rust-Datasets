#define MIN(x, y) ((x) < (y)) ? (x) : (y)

int coinChange(int* coins, int coinsSize, int amount){
    int cnt;
    int *f = (int *) malloc((amount + 1) * sizeof(int));
    f[0] = 0;
    /* 计算每种硬币最少的硬币数 */
    for (int i = 1; i <= amount; i++) {
        /* 默认拼不出来 */
        f[i] = 0x7FFFFFFF;
        /* 最后一步  */
        for (int j = 0; j < coinsSize; j++) {
            if (i >= coins[j] && f[i-coins[j]] != 0x7FFFFFFF) {
                f[i] = MIN(f[i], f[i - coins[j]]+1);
            }
        }
    }

    if (f[amount] == 0x7FFFFFFF) {
        cnt = -1;
    } else {
        cnt = f[amount];
    }
    
    free(f);
    return cnt;
}