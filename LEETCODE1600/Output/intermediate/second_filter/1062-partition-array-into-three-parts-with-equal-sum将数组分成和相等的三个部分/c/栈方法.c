bool canThreePartsEqualSum(int* A, int ASize){
    int sum =  0;
    for (int i=0; i<ASize; i++) sum += A[i]; // Done

    if (sum %3 != 0) return false;
    else sum /= 3;
    int i, temp = 0;
    int index = 0;
    for (i=0; i<ASize; i++){
        temp += A[i];
        if (temp == sum ){
            if (index==1){ return true; }
            else index=1;
            temp = 0;
        }
    }
    return false;
}