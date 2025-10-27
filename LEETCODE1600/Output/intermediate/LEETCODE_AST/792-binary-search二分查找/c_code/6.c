int search(int* nums, int numsSize, int target)
{
    int low=0,high=numsSize-1;//定义high和low以便于查找
    int mid;
    while(low<=high)//循环开始-
    {
        mid=(low+high)/2;
        if(nums[mid]==target)
            return mid;//首先判断其是否在中间相等
        else {if(nums[mid]>target) high=mid-1;//大于就让high成为mid-1
        else low=mid+1;}//小于让mid+1
    }//二分查找循环结束，最后return的一定是mid
    return(-1);
}