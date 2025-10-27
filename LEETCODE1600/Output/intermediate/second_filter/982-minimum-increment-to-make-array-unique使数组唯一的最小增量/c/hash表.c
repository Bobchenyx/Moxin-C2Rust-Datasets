int minIncrementForUnique(int* A, int ASize){
    int *hash = calloc(80000, sizeof(int));

    for (int i = 0; i < ASize; i++) {
        hash[A[i]]++;
    }

    int move = 0;
    for (int i = 0; i < ASize; i++) {
        if (hash[A[i]] > 1) {
            int j = A[i] + 1;
            while (hash[A[i]] > 1) {
                for (; hash[j]; j++) {
                    ;
                }
                hash[j] = 1;
                hash[A[i]]--;
                move += (j - A[i]);
            }
        }
    }

    return move;
}