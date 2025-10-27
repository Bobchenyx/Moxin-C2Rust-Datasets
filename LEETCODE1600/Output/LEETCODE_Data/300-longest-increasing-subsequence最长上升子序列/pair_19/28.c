int maxVal(int i,int j){
    if(i>j) return i;
    else return j;
}

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0) return 0;
    int *dp=(int*)malloc(sizeof(int)*numsSize);
    int i,j,ans=0;

    for(i=0;i<numsSize;i++){
        //细节，这样就不用单独初始化dp了
        dp[i]=1;
        for(j=0;j<i;j++){
            if(nums[i]>nums[j]) dp[i]=maxVal(dp[j]+1,dp[i]);
        }
        ans=maxVal(ans,dp[i]);
    }
    return ans;
}