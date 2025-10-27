/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void quickSort(int *arr,int start,int end)
 {   
    // printf("\n%d %d\n",start,end);
    // for(int i=start;i<=end;i++)
    // {
    //     printf("%d ",*(arr+i));
    // }
     int left=start;
     int right=end-1;
     int mid=*(arr+end);
     while(left<right)
     {
         while(*(arr+left)<mid && left<right) left++;
         while(*(arr+right)>=mid && right>left) right--;
         if(left<right)
         {
             int tmp=*(arr+left);
             *(arr+left)=*(arr+right);
             *(arr+right)=tmp;    
             left++;
             right--;        
         }   
                
     }
     if(*(arr+left)>mid)
     {
         *(arr+end)=*(arr+left);
         *(arr+left)=mid;
     }
     if(left>start)
     {
         quickSort(arr,start,left);
     }
     if(left<end-1)
     {
         quickSort(arr,left+1,end);
     }
     
 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    quickSort(arr,0,arrSize-1);
    int *ans;
    ans=(int *)malloc(k*sizeof(int));
    for(int i=0;i<k;i++)
    {
        *(ans+i)=*(arr+i);
    }
    *returnSize=k;
    return ans;
}