int removeDuplicates(int* nums, int numsSize)
{
    //伪代码
    //设置双指针，同时遍历
    //一个指向需要判断的位置
    //一个指向可以修改的位置
    int p1=0;
    int p2=1;
    int i=1;
    if(numsSize!=0)
    {
        for(int i=1;i<=numsSize-1;i++)
        {
            if(nums[p1]!=nums[p1+1])
            {
                p1++;
                nums[p2]=nums[p1];
                p2++;
            }
            else
            {
                p1++;
            }
        }
        return p2;
    }
    else
    {
        return 0;
    }
}