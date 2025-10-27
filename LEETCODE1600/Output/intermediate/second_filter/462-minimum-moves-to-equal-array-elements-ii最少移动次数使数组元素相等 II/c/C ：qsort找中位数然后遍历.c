int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int minMoves2(int* nums, int numsSize){
    int mid;
    int count = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    if (numsSize % 2) {
        mid =  nums[(numsSize + 1)/ 2 - 1];
    } else {
        mid = (nums[numsSize / 2 - 1] + nums[numsSize / 2]) / 2;
    }
    
    for (int i = 0; i < numsSize; i++) {
        count += (nums[i] - mid > 0 ? nums[i] - mid : mid - nums[i]);
    }

    return count;
}