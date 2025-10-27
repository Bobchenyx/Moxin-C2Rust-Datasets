int CmpFuncUp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int FindFirstLargerNum(int *nums, int numsSize, int num) {
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] > num) {
            return i;
        }
    }

    return 0;
}

void nextPermutation(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return;
    }

    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            int pos = FindFirstLargerNum(&nums[i], numsSize - i, nums[i - 1]);
            int tmp = nums[i + pos];
            nums[i + pos] = nums[i - 1];
            nums[i - 1] = tmp;
            qsort(&nums[i], numsSize - i, sizeof(int), CmpFuncUp);
            return;
        }
    }

    qsort(nums, numsSize, sizeof(int), CmpFuncUp);
    printf("sort up");

}