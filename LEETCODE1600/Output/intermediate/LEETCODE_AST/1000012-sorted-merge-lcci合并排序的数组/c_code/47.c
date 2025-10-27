void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int a=m-1,b=n-1,i=m+n-1;
    for(;i>=0;i--){
        if(a<0) A[i]=B[b--];
        else if(b<0) A[i]=A[a--];
        else if(A[a]>B[b]){
            A[i]=A[a--];
        }
        else {
            A[i]=B[b--];
        }
    }
}