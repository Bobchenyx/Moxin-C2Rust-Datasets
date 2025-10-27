#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxSubArrayLen(int* nums, int numsSize, int k){
    int *preSum = (int *)calloc(1, sizeof(int) * (numsSize + 1));
    int i, tmp, j, ans;

    if (numsSize == 0) {
        return 0;
    }

    for (i = 0; i < numsSize; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    ans = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = numsSize - 1; j >= i; j--) {
            if (preSum[j + 1] - preSum[i] == k) {
                ans = MAX(ans, j - i + 1);
            }
        }
    }
    free(preSum);
    return ans;
}