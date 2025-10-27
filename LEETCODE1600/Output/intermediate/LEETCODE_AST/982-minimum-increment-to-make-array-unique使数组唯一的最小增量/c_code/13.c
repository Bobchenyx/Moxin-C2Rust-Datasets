int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int minIncrementForUnique(int* A, int ASize){
    qsort(A, ASize, sizeof(int), cmpfunc);
    int i, diff, sum = 0, num = 0;
    for(i = 1;i < ASize;i ++){
        diff = A[i] - A[i - 1];
        if(diff == 0){
            num ++;
        }
        else if(diff <= num){
            sum += (num + num + 1 - diff) * diff / 2;
            num += 1 - diff;
        }
        else{
            sum += num * (num + 1) / 2;
            num = 0;
        }
    }
    sum += num * (num + 1) / 2;
    return sum;
}