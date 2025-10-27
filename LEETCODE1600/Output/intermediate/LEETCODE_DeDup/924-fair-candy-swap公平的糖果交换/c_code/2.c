int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    int dif,sumA,sumB,i,j;
    for(i=0;i<ASize;i++)//求出总和
        sumA=sumA+A[i];
    for(i=0;i<BSize;i++)
        sumB=sumB+B[i];

        dif=sumB-sumA;
    *returnSize=2;
    int *returnnums=(int *)malloc(sizeof(int)*(*returnSize));
    for(j=0;j<BSize;j++)
    {
            if(B[j]>dif/2)
            for(i=0;i<ASize;i++)
                if(B[j]-A[i]==dif/2)
                {
                    returnnums[0]=A[i];
                    returnnums[1]=B[j];
                    return returnnums;//用break就会超过时间
                }
    }
    return returnnums;  
}