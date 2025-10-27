int dominantIndex(int* nums, int numsSize){
    int i,max=0,maxsec=0,maxi=0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>max)//优先满足第一大元素的判断
        {
            maxsec=max;
            maxi=i;
            max=nums[i];
        }
        else if(nums[i]>maxsec)//其次满足第二大元素的判断
        {
            maxsec=nums[i];
        }
    }
    if(max<2*maxsec)
        return -1;
    return maxi;
}