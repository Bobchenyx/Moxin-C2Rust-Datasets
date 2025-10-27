int comparefun(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr,arrSize,sizeof(int), comparefun);
    *returnSize = k;
    return arr;
}