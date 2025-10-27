int cmp(const void* a, const void* b) 
{   
    if (*((int *)a) > *((int *)b)) {
        return 1;
    } else if (*((int *)a) < *((int *)b))
    {
        return -1;
    } else {
        return 0;
    }
}

int arrayPairSum(int* nums, int numsSize){

    if (numsSize < 1) {
        return 0;
    }
    if (nums == NULL) {
        return 0;
    }
    //先排序
    qsort(nums, numsSize, sizeof(int), cmp);
    //取奇数的数字累加
    int sum = 0;
    for(int i; i < numsSize - 1; i = i + 2) {
        sum = sum + nums[i];
    }
    return sum;

}