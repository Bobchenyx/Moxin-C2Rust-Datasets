int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
     return 0;
    }
    //！
    int slowNumber = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[slowNumber] == nums[i]) {
    
        } else {
            slowNumber += 1;
            nums[slowNumber] = nums[i];
        }
    }
    
    return  slowNumber + 1;
}