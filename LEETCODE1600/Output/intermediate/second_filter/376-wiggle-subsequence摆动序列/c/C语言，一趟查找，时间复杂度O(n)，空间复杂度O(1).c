int wiggleMaxLength(int* nums, int numsSize){
    int ret = 0;
    int i = 1;
    
    if (0 == numsSize)
    {
        return 0;
    }
    
    ret = 1;

    while (i < numsSize)
    {
        if (nums[i] != nums[0])
        {
            break;
        }
        i++;
    }
    
    while (i < numsSize)
    {
        if (nums[i] > nums[i-1])
        {
            ret++;
            while (i < numsSize)
            {
                if (nums[i] < nums[i-1])
                {
                    break;
                }
                i++;
            }
        }
        else if (nums[i] < nums[i-1])
        {
            ret++;
            while (i < numsSize)
            {
                if (nums[i] > nums[i-1])
                {
                    break;
                }
                i++;
            }
        }
    }
    
    return ret;
}