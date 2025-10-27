int removeElement(int* nums, int numsSize, int val){
    int length=0;
    for(int iter=0;iter<numsSize;++iter)
        if(nums[iter]!=val)
            nums[length++]=nums[iter];
    return length;
}