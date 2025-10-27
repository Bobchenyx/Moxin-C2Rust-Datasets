int findRepeatNumber(int* nums, int numsSize){
    int tmp = 0;
    int i = 0;
    
       
    if((nums == NULL)||(numsSize <= 0))
        return -1;

    for(i = 0; i < numsSize; i++)
    {
        if((nums[i] < 0)||(nums[i] > numsSize - 1))
            return -1;
    }
  
    for(int i = 0; i < numsSize; i++)
    { 
        while(i != nums[i])
        {
            if(nums[nums[i]] == nums[i])
            {
                return nums[i];
            }
            tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;
        }
    }
    
    return -1;
}