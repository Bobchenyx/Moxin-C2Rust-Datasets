/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;    
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
    int *result=calloc(k,sizeof(int));
    *returnSize = k;
    
    qsort(arr,arrSize,sizeof(int),comp) ;
    for(int i=0; i<k; i++)
    {
        result[i]= arr[i];
    }

    return result;
}