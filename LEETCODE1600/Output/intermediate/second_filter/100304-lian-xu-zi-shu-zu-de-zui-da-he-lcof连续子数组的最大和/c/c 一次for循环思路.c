int maxSubArray(int* nums, int numsSize){
    int ans = nums[0];
    int curSum = nums[0];
    for(int i = 1;i<numsSize;i++){
        if((curSum + nums[i]) < nums[i])   //如果前面的和加上“我”比我还小，那就从“我”重新开始
            curSum = nums[i];
        else
            curSum += nums[i];
        if(ans<curSum)
            ans = curSum;
    }
    return ans;
}