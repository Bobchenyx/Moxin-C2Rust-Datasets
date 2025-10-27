bool checkPossibility(int* nums, int numsSize){
    int temp = 0;
    int j;
    int tempNum;
    for(int i = 0;i<numsSize - 1;i++)
    {
        if(nums[i] > nums[i+1])
        {
            tempNum = nums[i];
            nums[i] = nums[i+1];
            j = i;
            break;
        }
    }
    for(int i = 0;i<numsSize - 1;i++)
    {
        if(nums[i] <= nums[i+1])
        {
            temp++;
        }
    }
    if(temp == numsSize - 1)
    {
        return true;
    }
    else
    {
        nums[j] = tempNum;
        nums[j+1] = tempNum;
    }
    temp = 0;
    for(int i = 0;i < numsSize-1;i++)
    {
        if(nums[i] <= nums[i+1])
        {
            temp++;
        }
    }
    if(temp == numsSize - 1)
    {
        return true;
    }
    else
        return false;
    

    return 0;

}