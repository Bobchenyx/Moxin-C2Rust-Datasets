/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void mysort(int* arr, int k, int left, int right){
    int i = left, j = right, temp = arr[i];
    while(j > i){
        for(;arr[j] >= temp && j > i;j --);
        arr[i] = arr[j];
        for(;arr[i] <= temp && i < j;i ++);
        arr[j] = arr[i];
    }
    arr[i] = temp;
    if(i - left + 1 < k)
        mysort(arr, k - i + left - 1, i + 1, right);
    else if(i - left + 1 > k)
        mysort(arr, k, left, i - 1);
    else
        return;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(k == 0){
        *returnSize = 0;
        return NULL;
    }
    int i, *result = (int*)calloc(k, sizeof(int));
    *returnSize = k;
    mysort(arr, k, 0, arrSize - 1);
    for(i = 0;i < k;result[i] = arr[i], i ++);
    return result;
}