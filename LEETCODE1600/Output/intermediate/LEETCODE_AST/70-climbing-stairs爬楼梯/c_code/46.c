int climbStairs(int n){
    int step[2] = {0, 1};
    for (int i = 0; i < n; ++i) {
        step[i & 1] = step[i & 1] + step[(i - 1) & 1];
    }
    return step[(n - 1) & 1];
}