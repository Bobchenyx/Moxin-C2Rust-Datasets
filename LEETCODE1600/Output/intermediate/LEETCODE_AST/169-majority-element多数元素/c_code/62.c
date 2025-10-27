int majorityElement(int* nums, int numsSize){
    int sum = 0;
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        if (sum == 0) {
            ret = nums[i];
            sum = 1;
            continue;
        }
        sum += (nums[i] == ret) ? 1 : -1;
    }
    return ret;
}