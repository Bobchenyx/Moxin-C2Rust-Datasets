int majorityElement(int* nums, int numsSize){
    int c=1;
    int maj=nums[0];
    for(int i=1;i<numsSize;++i){
        if(maj==nums[i])
            ++c;
        else
            --c;
        if(c==0)
            maj=nums[i+1];
    }
    return maj;
}