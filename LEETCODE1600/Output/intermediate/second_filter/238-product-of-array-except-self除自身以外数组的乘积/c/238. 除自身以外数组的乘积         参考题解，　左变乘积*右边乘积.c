/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int i=0, product = 1;
    int *res = malloc(numsSize * sizeof(int));

    for (i = 0; i < numsSize; i++) {
        res[i] = product;
        product = product * nums[i];
    }

    product = 1;
    for (i = numsSize - 1; i >=0 ; i--) {
        res[i] = res[i] * product;
        product = nums[i]*product;
    }
    
    *returnSize = numsSize;
    return res;
}