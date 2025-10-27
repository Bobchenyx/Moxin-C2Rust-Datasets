int majorityElement(int* nums, int numsSize)
{
    // 设置两个变量 一个叫做candidate,一个叫做count
    int candidate=nums[0], count=1, i;
    for(i=1; i<numsSize; i++)
    {
        if(candidate == nums[i])
        {
            count++;
        }
        else
        {
            count--;
            if(count<0)
            {
                candidate = nums[i];
                count = 1;
            }
        }
    }
    return candidate;
}