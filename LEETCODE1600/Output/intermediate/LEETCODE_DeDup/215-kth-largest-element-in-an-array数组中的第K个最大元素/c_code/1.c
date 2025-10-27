int cmp(void *x, void *y)
{
    return *(int *)y - *(int *)x;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[k - 1];
}