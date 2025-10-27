int numWays(int n){
    int a=1,b=1,c;
    for(int i=0;i<n;i++)
    {
        c=a;
        a=b;
        b=(a+c)%1000000007;
    }
    return a;
}