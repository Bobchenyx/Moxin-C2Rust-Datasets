int climbStairs(int n){
          int *a=(int *)malloc(sizeof(int)*1000);
           int i;
           a[1]=1;
           a[2]=2;
           for(i=3;i<=n;i++)a[i]=a[i-1]+a[i-2];
           return a[n];
}