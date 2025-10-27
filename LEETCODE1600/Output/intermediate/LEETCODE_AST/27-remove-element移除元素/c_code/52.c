int removeElement(int* nums, int numsSize, int val){
    int i, j, count = 0, result = 0;
//    if (nums[numsSize - 1] == val) {
//        count ++;
//    }
    for (i = numsSize - 1; i >= 0; --i) {
        if (nums[i] == val){
            for (j = 0; j < result; ++j) {
                nums[i + j] = nums[i + 1 +j];
            }
//            memcpy(&nums[i], &nums[i + 1], result * sizeof(int));
            count ++;
        }
        result ++;
    }
    return result - count;
}