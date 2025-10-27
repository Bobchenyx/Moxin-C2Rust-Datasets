/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int i,j;
    int temp;
    int*ans=(int*)malloc(sizeof(int)*k);
    for(j=1;j<arrSize;j++){
        temp=arr[j];
        for(i=j;i>0&&arr[i-1]>temp;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[i]=temp;
    }
    for(i=0;i<k;i++) ans[i]=arr[i];
    *returnSize = k;
    return ans;
      
     

}