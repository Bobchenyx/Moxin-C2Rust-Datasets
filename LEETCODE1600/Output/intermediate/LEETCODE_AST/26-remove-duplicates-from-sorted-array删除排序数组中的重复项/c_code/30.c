int removeDuplicates(int* nums, int numsSize)
{
    if (nums == NULL || !numsSize) return 0; 
    int num = *nums, count = 1; 
    for (int* p = nums; p != nums + numsSize; p++) {
        if (*p != num) { 
            num = *p;
            *(nums+count) = num;
            count++;
        }
    }
    return count; 
}