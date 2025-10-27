int peakIndexInMountainArray(int* A, int ASize){
    int i=0,j=ASize-1;
    while(1){
        if(A[i+1]<A[i])
            return i;
        if(A[j-1]<A[j])
            return j;
        i++;
        j--;
    }
    return 0;
}