/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void swap(int *a, int *b);
 void quicksort(int* a,int left, int right);

int* sortedSquares(int* A, int ASize, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*ASize);
    *returnSize=ASize;
    for(int i=0;i<ASize;i++)
        A[i]=A[i]*A[i];
    
    // quicksort(res,0,(*returnSize)-1);
    int left=0,right=ASize-1;
    int i=right;
    while(left<right)
    {
        if(A[left]>=A[right]&&left<right)
        {
            res[i--]=A[left++];
        }
        if(A[left]<=A[right]&&left<right)
        {
            res[i--]=A[right--];
        }
    }
    res[0]=A[left];




    return res;
}

// void quicksort(int* a,int left, int right)
// {
//     if(left>right)
//         return;
//     int tag=a[left];
//     int i=left;
//     int j=right;
//     while(i<j)
//     {
//         while(a[j]>=tag&&i<j)
//             j--;
//         while(a[i]<=tag&&i<j)
//             i++;
//         if(i<j)
//             swap(&a[i],&a[j]);
//     }
//     swap(&a[i],&a[left]);
//     quicksort(a, 0, i-1);
//     quicksort(a, i+1, right);
// }

// void swap(int *a, int *b){
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }