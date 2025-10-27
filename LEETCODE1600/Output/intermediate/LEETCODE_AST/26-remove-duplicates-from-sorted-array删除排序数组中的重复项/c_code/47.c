int removeDuplicates(int* nums, int numsSize){
    if(numsSize<2) return numsSize;

    int i=0,j=1;
    for(;j<numsSize;++j)
        if(nums[i]^nums[j])     
            nums[++i]=nums[j];

    return i+1;
}