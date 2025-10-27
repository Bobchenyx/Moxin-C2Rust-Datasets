int massage(int* nums, int numsSize){
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
    int maxVal(int x,int y);
    int i;
    int *dp=(int*)malloc(numsSize*sizeof(int));
    dp[0]=nums[0];
    dp[1]=maxVal(nums[0],nums[1]);
    for(i=2;i<numsSize;i++){
        dp[i]=maxVal(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[numsSize-1];
}

int maxVal(int x,int y){
    if(x>y) return x;
    else return y;
}