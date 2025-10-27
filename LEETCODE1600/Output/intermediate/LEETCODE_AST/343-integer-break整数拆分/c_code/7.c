int integerBreak(int n){
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    int cnt_3 = n / 3;
    int mod = n % 3;
    int cnt_2 = mod / 2;
    if (1 == mod) {
        cnt_3 -= 1;
        cnt_2 = 2;  // 这种情况为 4/2
    }
    // cnt_2如果不用余数计算可以在这里这么写
    // int cnt_2 = (n - cnt_3 * 3) / 2;

    return pow(3,cnt_3) * pow(2, cnt_2);
}