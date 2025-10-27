int searchInsert(int* nums, int numsSize, int target){
    int cur = 0;
    while (cur < numsSize && nums[cur] < target) cur++;
    return cur;
}