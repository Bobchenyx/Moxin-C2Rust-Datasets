int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long f1, f2, temp, value;
    long long modVal = 1e9 + 7;
    f1 = 1; f2 = 0;
    
    while (--n > 0) {
        value = f1 % modVal + f2 % modVal;
        temp = f1;
        f1 = value;
        f2 = temp;
    }
    
    return value % modVal;
}