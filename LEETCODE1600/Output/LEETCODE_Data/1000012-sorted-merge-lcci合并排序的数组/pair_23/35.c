void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int j = 0;
    int temp;
    for(int i = ASize - BSize;i < ASize;i++){
        A[i] = B[j];
        j++;
    }
    for(int i=ASize-1;i > 0;i--){
        for(int k=0;k < i;k++){
            if(A[k] > A[k+1]){
                temp = A[k];
                A[k] = A[k+1];
                A[k+1] = temp;
            }
        }
    }
    return A;
}