int maxSubArray(int* nums, int numsSize){

    if(numsSize==1) return nums[0];
    if(numsSize==0) return 0;

    int large[numsSize];
    large[0]=nums[0];
    for(int i=1;i<numsSize;i++) //从第二位开始，计算累积到此位的最大值
    {
        if((large[i-1]+nums[i] )>nums[i] ) large[i] = large[i-1]+nums[i];
        else large[i] = nums[i];
    }

    for(int i=1 ; i<numsSize;i++)   //逐位将当前最大值延续。
    {
        if(large[i-1]>large[i]) large[i] = large[i-1];
    }

    return large[numsSize-1];
}