int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int min1 = m;
    int min2 = n;
    for(int i = 0; i < opsSize; i++) {
        min1 = fmin(min1, ops[i][0]);
        min2 = fmin(min2, ops[i][1]);
    }
    return min1 * min2;
}