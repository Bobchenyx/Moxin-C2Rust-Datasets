/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){
    int high=arrSize-1;
    int max=arr[high];
    arr[high--]=-1;
    while(high>=0)
    {
        int temp=arr[high];
        arr[high--]=max;
        max=max>temp?max:temp;
    }
    *returnSize=arrSize;
    return arr;
}