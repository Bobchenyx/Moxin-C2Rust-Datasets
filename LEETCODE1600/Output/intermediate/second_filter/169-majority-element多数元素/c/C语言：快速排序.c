int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int cnt = 1;
    for (int i = 1; i < numsSize; i++){
        if (nums[i] == nums[i - 1])
            cnt++;
        if (cnt > numsSize / 2)
            return nums[i];
        if (nums[i] != nums[i - 1])
            cnt = 1;
    }
    return nums[0];//the array only has one number.
}