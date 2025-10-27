/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int *sum=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n/2;i++)
    {
        sum[i]=i+1;
        sum[n-i-1]=(i+1)*(-1);
    }
    if(n%2!=0)
    {
        sum[n/2]=0;
    }
    *returnSize=n;
    return sum;
}