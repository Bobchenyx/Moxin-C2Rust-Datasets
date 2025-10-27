int cmp(const void *a, const void *b) {
    const int l = *(int *)a;
    const int r = *(int *)b;
    return (l > r) ? 1 : -1;
}
int minIncrementForUnique(int* A, int ASize){
    if (A == NULL || ASize <= 1) {
        return 0;
    }
    qsort(A, ASize, sizeof(int), cmp);
    int count = 0;
    int num = A[0];
    int index = 1;
    for (int i = 1; i < ASize; i++) {
        if (A[i] == A[i - 1]) {
            if (A[i] + 1 > num) {
                index = i + 1;
                num = A[i] + 1;
            }            
            while (index < ASize) {
                if (A[index] > num) {
                    break;
                }else {
                    num = A[index] + 1;
                    index++;
                }
            }
            if (num > A[i]) {
                count += (num - A[i]);
                num++;
            }
        }
    }
    return count;
}