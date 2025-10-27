int numWays(int n){
    int p[n+2];
    p[0]=1;//初始位置为第0层也就是不用跳
    p[1]=1;//跳到第1层需要一种方法
    int mod=1000000007;//取模
    for(int i=2;i<=n;i++)
    {
        p[i]=(p[i-1]+p[i-2])%mod;
    }//可以换成递归写法，个人觉得这样写更直观
    return p[n];


}