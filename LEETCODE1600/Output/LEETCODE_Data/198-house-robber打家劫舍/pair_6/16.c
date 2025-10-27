int rob(int* nums, int numsSize){
    int dp1=0,dp2=0,result=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]+dp1>dp2){
            result = nums[i]+dp1;
        }
            dp1 = dp2;
            dp2 = result;
    }
    return  result;
}