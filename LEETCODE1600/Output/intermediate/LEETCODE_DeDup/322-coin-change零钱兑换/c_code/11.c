int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

bool backtrace(int amount, int remain, int *coins, int coinsSize, int idx, int *cnt, int *min) {
    if (remain == 0) {
        *min = (*min == -1) ? *cnt : fmin(*min, *cnt);
        return true;
    }

    while (idx < coinsSize && coins[idx] > remain) idx++;
    if (idx >= coinsSize) return false;

    int trycnt = remain / coins[idx];
    int i;
    int flag = false;
    for (i=trycnt; i>=0; i--) {///>=0
        int tmp = *cnt;
        *cnt += i;
        bool ret = backtrace(amount, remain-coins[idx]*i, coins, coinsSize, idx+1, cnt, min);
        if (ret) flag = true;
        *cnt = tmp;
    }
    return flag;
}

int coinChange(int* coins, int coinsSize, int amount){
    qsort(coins, coinsSize, sizeof(int), cmp); 
    int cnt = 0;
    int min = -1;
    if (backtrace(amount, amount, coins, coinsSize, 0, &cnt, &min)) {
        return min;
    }
}