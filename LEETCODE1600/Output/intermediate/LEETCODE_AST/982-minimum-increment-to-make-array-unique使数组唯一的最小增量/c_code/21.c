int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int minIncrementForUnique(int* A, int ASize)
{
    if ((A == NULL) || (ASize == 0)) {
        return 0;
    }
    qsort(A, ASize, sizeof(A[0]), cmp);
    int i;
    int returnValue = 0;
    int tmp;
    for (i = 0; i < ASize - 1; i++) {
        if (A[i + 1] == A[i]) {
            A[i + 1]++;
            returnValue++; 
        } else if (A[i + 1] < A[i]) {
            tmp = A[i + 1];
            A[i + 1] = A[i] + 1;
            returnValue += A[i + 1] - tmp;
        }
    }

    return returnValue;
}