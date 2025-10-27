int removeElement(int* nums, int numsSize, int val){
    int real_num = 0;
    int i = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            real_num++;
            nums[real_num - 1] = nums[i];
        }
    }

    return real_num;
}