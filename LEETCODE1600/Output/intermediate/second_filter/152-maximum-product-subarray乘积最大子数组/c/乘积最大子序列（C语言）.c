int maxProduct(int* nums, int numsSize){
    // 申请空间
    int *maxEr = (int *)calloc(sizeof(int), numsSize);
    int *minEr = (int *)calloc(sizeof(int), numsSize);
    int result = nums[0];
    maxEr[0] = minEr[0] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > 0) {
            maxEr[i] = max(maxEr[i-1]*nums[i], nums[i]);
            minEr[i] = min(minEr[i-1]*nums[i], nums[i]);
        } else if (nums[i] < 0){
            maxEr[i] = max(minEr[i-1]*nums[i], nums[i]);
            minEr[i] = min(maxEr[i-1]*nums[i], nums[i]);
        } else {
            maxEr[i] = 0;
            minEr[i] = 0;
        }
    }
    for (int i = 1; i < numsSize; i++) {
        result = maxEr[i] > result ? maxEr[i] : result;
    }

    // 释放空间
    free(maxEr);
    free(minEr);

    return result;
}

int min(int x, int y) {
    return x > y ? y : x;
}

int max(int x, int y) {
    return x > y ? x : y;
}