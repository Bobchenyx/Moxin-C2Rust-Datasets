int maxSubArray(int* nums, int numsSize){
    int t = nums[0];
    int sum = nums[0];
    int i;
    for(i=1;i<numsSize;i++)
    {
        if(t>0)
        {
            t+=nums[i];
        }
        else
        {
            t = nums[i];
        }
        if(sum<t)
        {
            sum=t;
        }
    }
    return sum;

}