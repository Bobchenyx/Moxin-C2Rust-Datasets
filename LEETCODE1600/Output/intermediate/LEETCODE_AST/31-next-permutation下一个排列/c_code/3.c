int cmp(const void *a, const void *b)
{
    return *(int*)a > *(int*)b;
}

void nextPermutation(int* nums, int numsSize){
    int i, j, tmp;
    if (numsSize <= 1) {
        return;
    }
    /* 从右向左找到递减序列的边界 */
    for (i = numsSize - 1; i > 0; i--) {
        if (nums[i] > nums[i-1]) {
            break;
        }
    }
    /* 整个数组递减 */
    if (i == 0) {
        qsort(nums, numsSize, sizeof(int), cmp);
        return;
    }
    /* 在递减序列里，从右向左找到第一个大于边界的数值，然后和边界进行互换 */
    tmp = nums[i - 1];
    for (j = numsSize - 1; j > (i - 1); j--) {
        if (nums[j] > tmp) {
            break;
        }
    }
    nums[i - 1] = nums[j];
    nums[j] = tmp;
    /* 将递减序列转换成递增序列 */
    qsort(&nums[i], numsSize - i, sizeof(int), cmp);
    return; 
}