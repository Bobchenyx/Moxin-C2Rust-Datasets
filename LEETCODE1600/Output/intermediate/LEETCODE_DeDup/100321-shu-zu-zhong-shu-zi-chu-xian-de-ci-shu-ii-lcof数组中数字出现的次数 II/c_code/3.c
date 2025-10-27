int cmp(const void *a, const void *b)
{
    long num1 = *(int*)a;
    long num2 = *(int*)b;
    return num1 - num2;
}

int singleNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int i;

    if (numsSize == 1) {
        return nums[0];
    }
    if (nums[0] != nums[1]) {
        return nums[0];
    }
    if (nums[numsSize - 1] != nums[numsSize - 2]) {
        return nums[numsSize - 1];
    }
    for (i = 3; i < numsSize - 2; i += 3) {
        if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) {
            return nums[i];
        }
    }

    return 0;
}