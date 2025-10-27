int climbStairs(int n){
    unsigned int a=1,b=2;
    int ans,i;
    if(n==1){
        return 1;
    }
    for(i=1;i<n;i++){
        ans=b;
        b=a+b;
        a=ans;
    }
    return ans;

}