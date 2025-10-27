int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0)return 0;
    if(numsSize==1)return 1;

    int maxLength[numsSize],max=0;
    for(int i=0;i<numsSize;++i)
    {
        maxLength[i]=1;
        for(int j=0;j<i;++j)
            if(nums[i]>nums[j])
                maxLength[i]=maxLength[i]>(maxLength[j]+1)?maxLength[i]:maxLength[j]+1;
        max=max>maxLength[i]?max:maxLength[i];
    }
    return max;
}