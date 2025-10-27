int comp(int* a,int* b){
    return (*a)>(*b)?1:0;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    int i,j=0;
    qsort(nums,numsSize,sizeof(int),comp);
    return nums[numsSize-k];
}