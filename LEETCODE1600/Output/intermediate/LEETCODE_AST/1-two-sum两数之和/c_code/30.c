/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* arrRes = (int*) malloc (sizeof (int) * 2);
    for (int i = 0; i < numsSize; i++) {
        int ano = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (ano == nums[j]) {
                arrRes[0] = i;
                arrRes[1] = j;
                *returnSize = 2;
                return arrRes;
            }
        }
    }
    return NULL;
}