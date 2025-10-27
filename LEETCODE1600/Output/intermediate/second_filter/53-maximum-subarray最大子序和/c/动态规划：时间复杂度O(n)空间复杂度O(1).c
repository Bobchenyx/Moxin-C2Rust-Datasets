int maxSubArray(int* nums, int numsSize){
    int ret = nums[0];
    int dp = nums[0];
    int tmp = 0;
    int i = 1;
    for(; i < numsSize; i++){
        tmp = dp + nums[i];
        dp = (tmp > nums[i]) ? tmp : nums[i];
        ret = (ret > dp) ? ret : dp;
    }
    return ret;
}