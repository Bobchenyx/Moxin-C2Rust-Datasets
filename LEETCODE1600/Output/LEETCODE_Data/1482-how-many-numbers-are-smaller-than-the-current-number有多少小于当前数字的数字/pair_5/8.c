/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX_NUM 101

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int count[MAX_NUM] = { 0 };
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    if (ans == NULL) {
        return NULL;
    }
    for (int i = 0; i < numsSize; i++) {
        int littleCount = 0;
        for (int j = 0; j < nums[i]; j++) {
            littleCount += count[j];
        }
        ans[i] = littleCount;
    }
    *returnSize = numsSize;
    return ans;
}