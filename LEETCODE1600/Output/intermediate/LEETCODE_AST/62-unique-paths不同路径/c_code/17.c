int uniquePaths(int m, int n){
    if(m!=1&&n!=1)
    return C_((m+n-2),(m-1)<(n-1)?(m-1):(n-1));
    else
    return 1;
}
int C_(int x,int y){//求组合数
    long Qs,Product=x;
    for(Qs=1;Qs<(y<(x-y)?y:(x-y));Qs++)
    {
        Product*=(x-Qs);
    }
    return Product/Factorial(y<(x-y)?y:(x-y));
}
int Factorial(int x){//求阶乘
    if(x<=1)
    return 1;
    else
    return x*Factorial(x-1);
}