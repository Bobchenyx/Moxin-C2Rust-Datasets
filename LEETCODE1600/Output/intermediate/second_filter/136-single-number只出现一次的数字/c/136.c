int singleNumber(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) {
        return 0;
    }

    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res = res ^ nums[i];
    }

    return res;
}