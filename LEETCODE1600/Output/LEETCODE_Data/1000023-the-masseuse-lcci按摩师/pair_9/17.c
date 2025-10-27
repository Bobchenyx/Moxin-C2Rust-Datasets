int max(int a, int b){return a>b?a:b;}
int massage(int* nums, int n){
    /*
        dp[i] = max(dp[i]+dp[i-2],dp[i-1]);//状态转移方程
    */ 
    if(n<1) return 0;
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    int preDay = 0,tmax=0,yesterday=nums[0];

    for(int i=1; i<n; i++){
        tmax = max(nums[i]+preDay,yesterday);
        preDay = yesterday;
        yesterday = tmax;
    }
    return tmax;
}