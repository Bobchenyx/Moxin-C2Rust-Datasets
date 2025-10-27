int singleNumber(int* nums, int numsSize){
    int output=nums[0];
    for(int i=1;i<numsSize;i++){
        output=output^nums[i];
    }
    return output;
}