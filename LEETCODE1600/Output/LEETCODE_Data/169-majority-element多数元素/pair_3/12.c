int majorityElement(int* nums, int numsSize){
    int i, num = nums[0], count = 0;
    for (i = 1; i < numsSize; i++)
    {
        count += (num == nums[i]) ? 1 : -1;
        if (count < 0) 
        {
            num = nums[i];
            count = 0;
        }
    }
    return num;
}