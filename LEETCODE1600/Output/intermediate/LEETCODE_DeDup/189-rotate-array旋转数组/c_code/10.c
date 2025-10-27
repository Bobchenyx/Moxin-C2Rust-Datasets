void rotate(int* nums, int numsSize, int k)
{
    k = k%numsSize;
    int value;
    for(int i = 0;i<k;i++)
    {
        value = nums[numsSize-1];
        for(int j = numsSize-1;j>0;j--)
        {
            nums[j]=nums[j-1];
        }
        nums[0]=value;
    }
}