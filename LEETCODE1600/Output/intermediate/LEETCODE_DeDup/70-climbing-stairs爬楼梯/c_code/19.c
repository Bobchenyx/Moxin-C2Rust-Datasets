int climbStairs(int n){
    // f(n) = f(n-1) + f(n-2)
    if ( n < 0 ) return 0;
    if (n <=2) return n;

    int fn1 = 1, fn2 = 2;
    int fn3;
    for (int i = 2 ;i < n; i++){
        fn3 = fn2 + fn1;
        fn1 = fn2;
        fn2 = fn3;
    }
    return fn3;

}