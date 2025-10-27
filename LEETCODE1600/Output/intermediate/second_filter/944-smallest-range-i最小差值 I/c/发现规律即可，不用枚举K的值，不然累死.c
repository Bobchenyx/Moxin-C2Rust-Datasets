int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int smallestRangeI(int* A, int ASize, int K){
    qsort(A, ASize, sizeof(int), cmp);

    int min = A[0];
    int max = A[ASize - 1];

    if (max - min <= 2 * K) {
        return 0;
    }

    return (max - min) - 2 * K;
}