int* sortedSquares(int* A, int ASize, int* returnSize){
    short i,j=0,k=ASize-1;
    for(i=0;i<ASize;i++) A[i]=A[i]*A[i];
    int* res=malloc(ASize*sizeof(int));
    while(i--)
        if(A[j]>A[k]) res[i]=A[j++];
        else res[i]=A[k--];
    *returnSize=ASize;
    return res;
}