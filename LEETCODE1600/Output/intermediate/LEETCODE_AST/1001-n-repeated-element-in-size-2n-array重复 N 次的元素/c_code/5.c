int repeatedNTimes(int* A, int ASize){
    int a[10000]={0};
    for(int i=0;i<ASize;i++){
        a[A[i]]++;
        if(a[A[i]]==2)
            return A[i];
    }
    return 0;
}