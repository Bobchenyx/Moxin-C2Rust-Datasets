int removeElement(int* nums, int numsSize, int val){
    int i = 0,index = 0;

    while(i < numsSize)
    {
        if(nums[i]!= val)
        {
            nums[index] = nums[i];
            index++;
        }
        i++;
    }
    return index;
}