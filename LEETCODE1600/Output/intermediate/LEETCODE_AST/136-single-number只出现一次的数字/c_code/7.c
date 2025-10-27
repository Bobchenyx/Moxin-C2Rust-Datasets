int singleNumber(int* nums, int numsSize){
    int XOR = nums[0];
    for(int i =1;i<numsSize;i++){
        XOR = XOR^nums[i];
    }
    return XOR;
}