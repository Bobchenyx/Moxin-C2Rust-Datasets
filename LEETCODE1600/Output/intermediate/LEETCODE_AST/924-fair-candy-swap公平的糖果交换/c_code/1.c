/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    int sumA=0,sumB=0;
    int *res=(int*)malloc(sizeof(int)*2);
    for(int i=0;i<ASize;i++)
        sumA+=A[i];
    for(int i=0;i<BSize;i++)
        sumB+=B[i];

    for(int i=0;i<ASize;i++)
    {
        for(int j=0;j<BSize;j++)
        {
            if((sumA-sumB)/2==A[i]-B[j])
            {
                res[0]=A[i];
                res[1]=B[j];
                break;
            }
        }
    }
    *returnSize=2;

    return res;

}