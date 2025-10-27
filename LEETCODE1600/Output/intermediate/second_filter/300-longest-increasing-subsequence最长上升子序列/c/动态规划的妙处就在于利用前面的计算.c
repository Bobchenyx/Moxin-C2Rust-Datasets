int lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int *len = calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        len[i] = 1;
    }

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && len[i] < len[j] + 1) {
                len[i] = len[j] + 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        if (len[i] > res) {
            res = len[i];
        }
    }

    return res;
}