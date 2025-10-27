void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i;
    int idxa = m-1;
    int idxb = n-1;
    
    for (i=m+n-1; i>=0; i--) {
        if (idxa == -1) A[i] = B[idxb--];
        else if (idxb == -1) A[i] = A[idxa--];
        else if (A[idxa] > B[idxb]) A[i] = A[idxa--];
        else A[i] = B[idxb--];
    }
}