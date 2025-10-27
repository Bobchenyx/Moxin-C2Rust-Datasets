int smallestRangeI(int* A, int ASize, int K){
    int f(int* a,int* b)
    {
        return *a>*b?1:0;
    }
    qsort(A,ASize,sizeof(int),f);
    if(K>=A[ASize-1]/2)
    {
        return 0;
    }
    else
    return A[ASize-1]-K-(A[0]+K);
}