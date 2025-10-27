/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    long n1 = *(int*)a;
    long n2 = *(int*)b;

    return n1 - n2;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = k;

    int *res = calloc(k, sizeof(int));
    for (int i = 0; i < k; i++) {
        res[i] = arr[i];
    }

    return res;
}