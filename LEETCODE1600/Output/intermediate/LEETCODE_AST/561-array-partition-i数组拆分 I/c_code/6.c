int cmp(int *a, int *b) {
    return *(int *)a > *(int *)b;
}
int arrayPairSum(int* nums, int numsSize){
    int i, j;
    int sum = 0;
    if (numsSize < 2) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);  //stdlib.h库中 快排函数
    for (sum = nums[0], i = 2; i < numsSize; i += 2) 
    {
        sum += nums[i];
    }
    return sum;
}