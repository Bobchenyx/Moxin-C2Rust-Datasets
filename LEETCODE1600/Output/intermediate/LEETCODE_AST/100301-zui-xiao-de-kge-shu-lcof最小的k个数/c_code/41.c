/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    for(int i=0;i<k;i++){
        for(int j=k;j<arrSize;j++){
            if(arr[i] > arr[j]){
                arr[i] = arr[i]^arr[j];//使用异或实现交换
                arr[j] = arr[i]^arr[j];
                arr[i] = arr[i]^arr[j];
            }
        }
    }
    *returnSize = k;
    return arr;
}