int Cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int i;
    int sum = 0;
    if ((nums == NULL) || (numsSize < k)) {
        *returnSize = 0;
        return NULL;
    }

    int *returnVal = (int *)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = 0;

    int *numsCpy = (int *)malloc(numsSize * sizeof(int));
    for (i = 0; i < numsSize - k + 1; i++) {
        memcpy(numsCpy, nums, numsSize * sizeof(int));
        qsort(&(numsCpy[i]), k, sizeof(numsCpy[0]), Cmp);
        returnVal[*returnSize] = numsCpy[i];
        (*returnSize)++;
    }

    return returnVal;
}