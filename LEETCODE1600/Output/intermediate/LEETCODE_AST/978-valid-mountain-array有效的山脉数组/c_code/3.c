bool validMountainArray(int* A, int ASize){
    int i;

    for (i = 0; i < ASize - 1 && A[i] < A[i + 1]; i++) {
    }

    if (i == 0 || i == ASize - 1) {
        return false;
    }

    while (i < ASize - 1) {
        if (A[i] <= A[i + 1]) {
            return false;
        }
        i++;
    }

    return true;
}