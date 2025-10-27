//对x 和 n 的值进行特殊处理
        //最小值：Integer.MIN_VALUE= -2147483648 （-2的31次方）
        //最大值：Integer.MAX_VALUE= 2147483647  （2的31次方-1）
        //这里需要使用long类型，因为如果传入的n = -2147483648； 那么转成正数就丢失，所以要使用long
double fastPow(double x, long n){
    if(0 == n)
        return 1.0;
    double half = fastPow(x, n/2);
    if(n%2 == 0){
        return half * half;
    }else{
        return half * half * x;
    }
}
double myPow(double x, int n){
    if(x == 1.0) return 1.0;
    if(x == -1){
        if(n%2 == 0) return 1.0;
        else return -1.0;
    }
    long long N = n;
    if(N < 0){
        x = 1/x;
        N = -N;
    }
    return fastPow(x, N);
}