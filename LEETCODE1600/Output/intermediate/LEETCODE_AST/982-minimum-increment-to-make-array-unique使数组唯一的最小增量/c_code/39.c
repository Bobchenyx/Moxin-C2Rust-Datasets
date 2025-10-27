int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int minIncrementForUnique(int* A, int ASize){
    int i, res=0;
    // 排序
    qsort(A, ASize, sizeof(int), cmpfunc);
    // 遍历并比较
    for(i=0; i<ASize-1; i++){
        if(A[i]>=A[i+1]){
            res += (A[i]-A[i+1]+1);
            A[i+1] = A[i] + 1;
        }
    }
    return res;
}