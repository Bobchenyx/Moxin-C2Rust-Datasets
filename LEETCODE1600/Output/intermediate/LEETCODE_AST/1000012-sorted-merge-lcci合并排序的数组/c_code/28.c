int cmp(void* a,void *b)
{
    return *(int*)a-*(int*)b;
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    for(int i=m,j=0;j<n;i++,j++)
        A[i]=B[j];
    qsort(A,m+n,sizeof(int),cmp);
}