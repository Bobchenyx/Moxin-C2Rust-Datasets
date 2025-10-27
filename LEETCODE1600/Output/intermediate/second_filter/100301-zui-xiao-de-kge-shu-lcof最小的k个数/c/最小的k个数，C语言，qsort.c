/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp_func(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
} 
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(k == 0 || arrSize == 0){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = k;
    int *result = (int *)calloc(k, sizeof(int));
    qsort(arr, arrSize, sizeof(int), cmp_func);
    for(int i = 0; i < k; i++){
        result[i] = arr[i];
    }
    return result;
}