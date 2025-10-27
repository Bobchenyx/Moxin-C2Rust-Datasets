int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minIncrementForUnique(int* A, int ASize){
    int count = 0;
    qsort(A, ASize, sizeof(int),compare);
    int i;
    for(i = 1; i < ASize; i++) {
    //    printf(" A [%d] %d\n", i, A[i]);
        if (A[i] <= A[i - 1]) {
            count += A[i - 1] - A[i] + 1;
            A[i] = A[i - 1] + 1;
        } 
   //     printf(" new A [%d] %d\n", i, A[i]);
    }

    return count;
}