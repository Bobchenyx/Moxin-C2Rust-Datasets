//调用库函数
int cmp(const void *_a,const void* _b)
{
    return *(int *)_a-*(int *)_b;
}
int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums,numsSize,sizeof(int),cmp);
    return nums[numsSize-k];
}