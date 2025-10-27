int maxSubArray(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int max = nums[0];
    int i = 0, tmp = max;
    for(i = 1; i < numsSize; i++){
        tmp = tmp + nums[i];
        tmp = nums[i] > tmp ? nums[i] : tmp;
        max = max > tmp ? max : tmp;
    }
    return max;
}