int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    int length=1,num=nums[0];
    for(int iter=0;iter<numsSize;++iter)
        if(nums[iter]>num)
        {
            num=nums[iter];
            nums[length++]=num;
        }
    return length;
}