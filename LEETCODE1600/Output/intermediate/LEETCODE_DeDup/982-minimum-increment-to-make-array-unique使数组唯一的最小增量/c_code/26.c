int minIncrementForUnique(int* A, int ASize){
    if (A == NULL || ASize == 0) return 0;
    int set[80000] = {0};
    int min = A[0];
    int max = A[0];
    for (int i = 0; i < ASize; ++i) {
        set[A[i]]++; 
        min = A[i] < min ? A[i] : min;
        max = A[i] > max ? A[i] : max;
    }
    int itera = min;
    int cur = min;
    int step = 0;
    while (itera <= max) {
        if (set[itera] <= 1) {
            itera++;
            continue;
        }
        cur = cur > itera ? cur : itera + 1;
        while (set[cur] != 0) { cur++; };
        set[itera]--;
        set[cur]++;
        step += cur - itera;
    }
    return step;
}