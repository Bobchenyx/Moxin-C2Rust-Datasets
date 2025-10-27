int climbStairs(int n){
    if(n<=2)
        return n;
    else
    {
        int k1=1;
        int k2=2;
        for(int i=3;i<=n;i++)
        {
            int t=k1+k2;
            k1=k2;
            k2=t;
        }
        return k2;
    }
}