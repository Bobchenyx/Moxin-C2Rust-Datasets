comp(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}
int arrayPairSum(int* nums, int numsSize)
{
    int i;
    int sum = 0;
    qsort(nums, numsSize, sizeof(int), comp);
    for(i = 0; i < numsSize; i = i + 2) {
        sum = sum + nums[i];
    }
    return sum;
}