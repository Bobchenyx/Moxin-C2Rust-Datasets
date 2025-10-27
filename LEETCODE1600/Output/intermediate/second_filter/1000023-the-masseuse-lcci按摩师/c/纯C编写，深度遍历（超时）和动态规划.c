/*void dfs(int* nums,int numsSize,int start,int *temp,int *sum){
    for(int i=start;i<numsSize;i++){
        (*temp)+=nums[i];
        dfs(nums,numsSize,i+2,temp,sum);
        (*temp)-=nums[i];
    }
    if((*temp)>(*sum))
        (*sum)=(*temp);
    return;
}
int massage(int* nums, int numsSize){
    int sum=0,temp=0;
    dfs(nums,numsSize,0,&temp,&sum);
    return sum;
}*/
int Max(int a,int b){
    return (a>b)?a:b;
}
int massage(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    if(numsSize==1)
        return nums[0];
    int *dp=(int*)malloc(sizeof(int)*numsSize);
    dp[0]=nums[0];
    dp[1]=Max(nums[0],nums[1]);
    int i;
    for(i=2;i<numsSize;i++){
        dp[i]=Max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[i-1];
}