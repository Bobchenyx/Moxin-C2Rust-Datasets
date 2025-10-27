int trailingZeroes(int n){
    int res = 0;

    // 5 的个数就是 n / 5 + n / 25 + n / 125 ...
    while (0 < n)
    {
        res += n / 5;
        n /= 5;
    }

    return res;
}