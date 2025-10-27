int myCompare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int majorityElement(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1){
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), myCompare);
    return nums[numsSize / 2];
}