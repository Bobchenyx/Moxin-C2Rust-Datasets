void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int index, index1, index2;

    if (B == NULL || n <= 0) {
        return;
    }

    index = m + n -1;
    index1 = m - 1;
    index2 = n - 1;

    while (index1 >= 0 && index2 >= 0) {
        if (A[index1] > B[index2]) {
            A[index] = A[index1];
            index1--;
        } else {
            A[index] = B[index2];
            index2--;
        }
        index--;
    }

    while (index2 >= 0) {
        A[index] = B[index2];
        index--;
        index2--;
    }

}