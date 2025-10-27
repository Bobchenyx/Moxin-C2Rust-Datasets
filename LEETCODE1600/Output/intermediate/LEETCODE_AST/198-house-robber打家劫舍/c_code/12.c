int max(int a, int b) {
    return ((a > b) ?a:b);
}

int rob(int* nums, int numsSize){
    if (numsSize > 1) {
        int maxNum = max(nums[0], nums[1]);
        nums[1] = maxNum;
        for (int i = 2; i < numsSize; i++) {
            nums[i] = max(nums[i]+nums[i-2],nums[i-1]);
            if (nums[i] > maxNum) {
                maxNum = nums[i];
            }
        }
        return maxNum;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    return 0;
}