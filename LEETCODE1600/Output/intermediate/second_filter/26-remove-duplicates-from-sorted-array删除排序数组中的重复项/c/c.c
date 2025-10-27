int removeDuplicates(int* nums, int numsSize){
    int real_num = 0;
    int i = 0;

    if(numsSize)
    {
        real_num = 1;
    }

    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] != nums[real_num - 1])
        {
            real_num++;
            nums[real_num - 1] = nums[i];
        }
    }

    return real_num;
}