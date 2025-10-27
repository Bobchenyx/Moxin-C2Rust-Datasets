/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int bitmask = 0;
    for (int i = 0; i < numsSize; i++) {
        bitmask ^= nums[i];
    }

    int diff = bitmask & (-bitmask);

    int x = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & diff) {
            x ^= nums[i];
        }
    }

    int *ans = calloc(2, sizeof(int));
    ans[0] = x;
    ans[1] = bitmask ^ x;
    *returnSize = 2;

    return ans;
}