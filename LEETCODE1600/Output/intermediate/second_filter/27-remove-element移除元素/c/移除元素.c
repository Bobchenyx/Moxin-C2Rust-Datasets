int removeElement(int* nums, int numsSize, int val){
    if(numsSize == 0) return numsSize;
    int n = 0;
    // 第一种方法
    for(int i = 0; i<numsSize; i++){
        if(nums[i] != val){
            nums[n++] = nums[i];
        }
    }
    return n;
    // 第二种方法
    // for(int i = 0; i<numsSize; i++)
    //     if(nums[i] != val) {
    //         nums[i-n] = nums[i];
    //     } else {
    //         n++;
    //     }
    // return numsSize - n;
}