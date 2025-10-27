int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    int len = 0;
    for ( int i = 0; i < numsSize; i++)
    {
        if (nums[len] != nums[i])   
            nums[++len] = nums[i];
    }
    return ++len;
}