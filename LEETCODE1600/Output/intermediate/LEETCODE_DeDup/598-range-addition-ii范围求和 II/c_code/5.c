int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int resM = m;
    int resN = n;
    for (int i = 0; i < opsSize; ++i) {
        resM = resM > ops[i][0] ? ops[i][0] : resM;
        resN = resN > ops[i][1] ? ops[i][1] : resN;
    }
    return resM * resN;
}