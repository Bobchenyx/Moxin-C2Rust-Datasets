int smallestRangeI(int* A, int ASize, int K){
    int i,max=A[0],min=A[0];
    for(i=0;i<ASize;i++){
        if(A[i]>max) max=A[i];
        if(A[i]<min) min=A[i];
    }
    return max-min>2*K?max-min-2*K:0;
}