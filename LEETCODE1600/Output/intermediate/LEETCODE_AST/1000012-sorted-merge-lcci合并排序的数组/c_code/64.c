int cmp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int j = 0;
    for(int i = m;i<ASize;i++)
    {
        A[i] = B[j];
        j++;
    }
    qsort(A,m+n,sizeof(int),cmp);
    return A;
}