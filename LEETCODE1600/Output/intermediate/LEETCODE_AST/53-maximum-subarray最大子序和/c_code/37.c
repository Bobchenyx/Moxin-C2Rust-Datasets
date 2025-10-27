int FindMaxCorssSubarray(int *nums,int low,int mid,int high)
{
    int leftsum = INT_MIN;
    int sum = 0;
    int i;
    for(i=mid;i>=low;i--)
    {
        sum += nums[i];
        if(sum>leftsum)
            leftsum = sum;
    }
    int rightsum = INT_MIN;
    sum = 0;
    for(i = mid+1;i<=high;i++)
    {
        sum += nums[i];
        if(sum > rightsum)
            rightsum = sum;
    }
    return leftsum+rightsum;
}
int FindMaximumSubarray(int *nums,int low,int high)
{
    if(high == low)
        return nums[low];
    else
    {
        int mid = floor((low+high)/2);
        int leftsum = FindMaximumSubarray(nums,low,mid);
        int rightsum = FindMaximumSubarray(nums,mid+1,high);
        int crosssum = FindMaxCorssSubarray(nums,low,mid,high);
        if(leftsum >= rightsum && leftsum >=crosssum)
            return leftsum;
        else if(rightsum>=leftsum && rightsum>=crosssum)
            return rightsum;
        else
            return crosssum;
    }
}
int maxSubArray(int* nums, int numsSize){
    return FindMaximumSubarray(nums,0,numsSize-1);
}