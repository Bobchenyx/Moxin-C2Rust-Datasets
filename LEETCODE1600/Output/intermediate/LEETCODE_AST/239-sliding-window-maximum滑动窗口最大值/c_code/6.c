/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_HTL(a, b) ((a) > (b) ? a : b)

int myMaxNum(int *arr, int begin, int end)
{
    int i;
    int max = arr[begin];
    
    for (i = begin; i < end; i++) {
        max = MAX_HTL(max, arr[i]);
    }

    return max;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *arr = NULL;
    int i;

    if (nums == NULL || k > numsSize || k <= 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    arr = (int *)malloc(sizeof(int) * (*returnSize));

    for (i = 0; i <= numsSize - k; i++) {
        arr[i] = myMaxNum(nums, i, i + k);
    }

    return arr;
}