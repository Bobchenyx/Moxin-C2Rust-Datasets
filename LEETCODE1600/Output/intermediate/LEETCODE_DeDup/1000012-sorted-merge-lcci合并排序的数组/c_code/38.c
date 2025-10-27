c []
int comp(const void*a, const void*b){
    return (*(int*)a - *(int*)b);
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    memcpy(&A[m],&B[0],sizeof(int)*n);
    qsort(A,m+n,sizeof(int),comp);
}