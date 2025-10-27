int majorityElement(int* nums, int numsSize){
    if(numsSize<=2)
    {
        return nums[0];
    }

    //先排序
    int i=0,j=0,temp=nums[0],count=1;
/*    for(i=0;i<numsSize;i++)
    {
        for(j=numsSize-1;j>i;j--)
        {
            if(nums[j]<nums[j-1])
            {
                temp=nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=temp;
            }
        }
    }
    return nums[numsSize/2];
    */
    for(i=1;i<numsSize;i++)
    {
        if(temp!=nums[i])
        {
            count--;
            if(count==0)
            {
                count=1;
                temp=nums[i];
            }
        }
        else
        {
            count++;
        }
    }
    return temp;
}