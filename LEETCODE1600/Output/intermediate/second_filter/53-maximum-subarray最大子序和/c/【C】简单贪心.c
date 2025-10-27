//贪心
int maxSubArray(int* nums, int numsSize){
    int max_sum = nums[0];
    for(int i=0, now_sum = 0; i<numsSize; ++i){
        now_sum = now_sum+nums[i] > nums[i] ? now_sum+nums[i] : nums[i];
        max_sum = now_sum > max_sum ? now_sum : max_sum;
    }
    return max_sum;
}