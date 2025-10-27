int fib(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    // n >= 2时循环取模
    int a = 0, b = 1;
    for(int i = 1; i < n; i++) {
        int temp = b;
        b = (a + b) % 1000000007;
        a = temp;
    }
    return b;
}