/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int f(int* a,int* b)
{
    return *a>*b?1:0;
}
int* sortedSquares(int* A, int ASize, int* returnSize){
    int* num=(int*)malloc(sizeof(int)*ASize);
    for(int i=0;i<ASize;i++)
    num[i]=A[i]*A[i];
    qsort(num,ASize,sizeof(int),f);
    *returnSize=ASize;
    return num;
}