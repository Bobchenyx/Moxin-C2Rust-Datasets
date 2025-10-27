/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    *returnSize=2;
    int *C=(int *)malloc(sizeof(int)*2);
    int sum1=0,sum2=0;
    for(int i=0;i<ASize;i++)
       sum1=sum1+A[i];
    for(int i=0;i<BSize;i++)
       sum2=sum2+B[i];
    for(int i=0;i<ASize;i++)
        for(int j=0;j<BSize;j++)
          if(sum1-A[i]+B[j]==sum2+A[i]-B[j])
          {
              C[0]=A[i];
              C[1]=B[j];
              return C;
          }
    return 0;
}