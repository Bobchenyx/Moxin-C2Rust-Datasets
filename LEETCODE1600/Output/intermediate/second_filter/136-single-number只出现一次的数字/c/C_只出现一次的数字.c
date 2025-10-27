int singleNumber(int* nums, int numsSize){
    int temp=nums[0];
    for(int i=1;i<numsSize;++i)
        temp=temp^nums[i];
    return temp;
}