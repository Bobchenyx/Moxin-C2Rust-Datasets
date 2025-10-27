void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i, j, k;
    // A 向后移动 BSize
    for(i=ASize-BSize-1; i>=0; i--){
        A[i+BSize] = A[i]; 
    }
    // 合并
    for(i=0,j=0,k=0; k<ASize; k++){
        if(i == ASize-BSize){
            while(j<BSize){
                A[k] = B[j];
                j++;
                k++;
            }
            break;
        }else if(j == BSize){
            while(i<ASize-BSize){
                A[k] = A[i+BSize];
                i++;
                k++;
            }
            break;
        }

        if(A[i+BSize]<B[j]){
            A[k] = A[i+BSize];
            i++;
        }else{
            A[k] = B[j];
            j++;
        }
    }
}