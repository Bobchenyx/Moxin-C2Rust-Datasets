int smallestRangeI(int* A, int ASize, int K){
    int min,max,aver;
    min=max=A[0];
    for(int i=0;i<ASize;i++){
        if(max<A[i])max=A[i];
        if(min>A[i])min=A[i];
    }
    aver=(min+max)/2;
    if(abs(max-aver)<=K&&abs(min-aver)<=K)
        return 0;
    return max-min-K-K;
}