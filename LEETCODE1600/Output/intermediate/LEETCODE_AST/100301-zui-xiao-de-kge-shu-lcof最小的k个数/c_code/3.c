/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if (!arr || arrSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    if (k >= arrSize) {
        *returnSize = arrSize;
        return arr;
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = k;
    return arr;
}