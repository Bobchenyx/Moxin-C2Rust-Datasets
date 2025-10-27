int fib(int n){
    int ansfib[101];
    ansfib[0]=0;
    ansfib[1]=1;
    if(n==0) return 0;
    else if(n==1) return 1;
    else
    {
         for(int i=2;i<=n;i++)
         {
            ansfib[i]=ansfib[i-1]+ansfib[i-2];
            ansfib[i]=ansfib[i]%(1000000007);
         }   
    }
    return ansfib[n];

}