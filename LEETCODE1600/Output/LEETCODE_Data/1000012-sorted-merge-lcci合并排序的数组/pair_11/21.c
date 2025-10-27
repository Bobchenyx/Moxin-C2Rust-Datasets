void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int total = m + n;

    while (n > 0) {
        while (m > 0 && B[n - 1] <= A[m - 1]) {
            A[total - 1] = A[m - 1];
            total--;
            m--;
        }
        A[total - 1] = B[n - 1];
        total--;
        n--;
    }
}