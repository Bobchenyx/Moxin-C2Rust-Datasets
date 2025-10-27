int compFun(void *a, void *b)
{
    return (*(int*)a - *(int*)b);
}

int minIncrementForUnique(int* A, int ASize)
{
    qsort(A, ASize, sizeof(int), compFun);
    int cnt = 0;
    for (int i = 1; i < ASize; i++) {
        if (A[i] <= A[i - 1]) {
            cnt += A[i - 1] + 1 - A[i];
            A[i] = A[i - 1] + 1;
        }
    }
    return cnt;
}