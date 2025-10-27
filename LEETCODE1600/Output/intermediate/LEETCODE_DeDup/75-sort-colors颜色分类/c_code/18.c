int Compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void sortColors(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return;
    }
    
    qsort(nums, numsSize, sizeof(int), Compare);
}