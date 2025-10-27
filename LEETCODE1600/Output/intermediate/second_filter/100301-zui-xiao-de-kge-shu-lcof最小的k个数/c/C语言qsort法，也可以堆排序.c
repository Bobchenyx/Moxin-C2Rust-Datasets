/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(void *a,void *b){
    return *(int*)a-*(int*)b;
}    
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr,arrSize,sizeof(int),comp);
    int *output=(int*)malloc(sizeof(int)*k);
    for(int i=0;i<k;i++){
        output[i]=arr[i];
    }
    *returnSize=k;
    return output;
}