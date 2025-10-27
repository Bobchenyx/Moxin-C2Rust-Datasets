int repeatedNTimes(int* A, int ASize){
    for(int i=0;i<ASize/2;i++){
        if(A[i]==A[i+ASize/2])
            return A[i];
    }
    return A[0]==A[1]?A[0]:A[1]==A[ASize/2]?A[1]:A[ASize/2+1];
}