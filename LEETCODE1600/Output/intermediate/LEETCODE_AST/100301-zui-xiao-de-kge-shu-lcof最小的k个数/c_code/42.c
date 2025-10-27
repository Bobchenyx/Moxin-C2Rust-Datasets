/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int i, j, min=10000, min_index;
    int* res = (int*)malloc(sizeof(int)*k);
    for(i=0; i<k; i++){
        for(j=0; j<arrSize; j++){
            if(min>arr[j]){
                min = arr[j];
                min_index = j;
            }
        }
        res[i] = min;
        arr[min_index] = 10000;
        min = 10000;
    }
    *returnSize = k;
    return res;
}