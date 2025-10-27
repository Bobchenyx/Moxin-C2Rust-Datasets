int removeDuplicates(int* nums, int numsSize){


    if(numsSize <= 1)
        return numsSize;

    int last = nums[0];

    for(int i = 1; i <= (numsSize-1); i++)
    {
        if(nums[i] == last)
        {
            for(int j = i; j <= (numsSize-2); j++)
            {
                nums[j] = nums[j+1];
            }
            i--;
            numsSize--;
        }
        else
        {
            last = nums[i];
        }
    }
    return numsSize;     
}