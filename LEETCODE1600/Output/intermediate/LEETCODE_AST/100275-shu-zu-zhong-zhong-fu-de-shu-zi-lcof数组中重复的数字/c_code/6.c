int findRepeatNumber(int* nums, int numsSize){
    char tmp[numsSize];
    int i;
    memset(tmp, 0, numsSize);
    for(i=0;i<numsSize;i++){
        if(tmp[nums[i]])
            return nums[i];
        tmp[nums[i]] = 1;
    }
    return -1;
}