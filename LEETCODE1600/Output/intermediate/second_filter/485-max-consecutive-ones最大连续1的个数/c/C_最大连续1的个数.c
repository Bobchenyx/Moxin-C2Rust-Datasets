int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max=0,sum=0;
    for(int i=0;i<numsSize;++i)
        if(nums[i]==1)
            ++sum;
        else
        {
            max=max>sum?max:sum;
            sum=0;
        }
    return max>sum?max:sum;
}