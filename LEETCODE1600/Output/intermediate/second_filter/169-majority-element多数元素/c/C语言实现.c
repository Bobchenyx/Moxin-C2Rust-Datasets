int majorityElement(int* nums, int numsSize){
    int value,count=0;
    value=nums[0];
    for(int i=0;i<numsSize;i++)
    {
        if(value==nums[i])
            count++;
        else
            count--;
        if(count<=0)
            value=nums[i+1];
    }
    return value;
}