/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){

    if ( numsSize * k == 0 ) {
        *returnSize = 0;
        return NULL;
        
    }
    *returnSize = numsSize - k + 1;
    int *ret = (int *)malloc(sizeof(int) * *returnSize);

    for (int i = 0; i < *returnSize; i++){
        int max = nums[i];
        for ( int j = i; j < i+k; j++){
            max = max < nums[j] ? nums[j] : max;
        }
        ret[i] = max;
    }
    return ret;

}