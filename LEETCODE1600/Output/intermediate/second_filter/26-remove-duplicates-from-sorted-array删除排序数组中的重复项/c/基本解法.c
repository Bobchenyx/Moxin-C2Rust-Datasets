int removeDuplicates(int* nums, int numsSize){
    int i, j;
    if(numsSize == 0) return 0;
    for(i=0,j=0; j<numsSize; j++)
    {
        if(nums[j] != nums[i])
        {
            i++;
            nums[i]=nums[j];
        }
    }
    return numsSize = i+1;
}