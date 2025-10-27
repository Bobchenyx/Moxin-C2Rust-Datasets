int rob(int* nums, int numsSize){
    if(numsSize<=0)return 0;
    if(numsSize==1)return nums[0];
    if(numsSize==2)return nums[0] > nums[1] ? nums[0] : nums[1];
    nums[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    int max = nums[1];
    for(int i=2;i<numsSize;i++){
        nums[i] = nums[i] + nums[i-2] > nums[i-1] ? nums[i] + nums[i-2] : nums[i-1];
        max = max > nums[i] ? max : nums[i];
    }
    return max;
}