int comp(int *a, int *b){
    return *a < *b;
}
int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), comp);
    return nums[k-1];
}