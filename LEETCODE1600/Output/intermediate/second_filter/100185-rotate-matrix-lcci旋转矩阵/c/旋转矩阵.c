void rotate(int** matrix, int matrixSize, int* matrixColSize){
    const int N = matrixColSize[0] - 1;
    int l = 0, r = N, t, i;
    while(l <= r) {
        for(i = l; i < r; ++i) {
            t = matrix[l][i];
            matrix[l][i] = matrix[N-i][l];
            matrix[N-i][l] = matrix[N-l][N-i];
            matrix[N-l][N-i] = matrix[i][N-l];
            matrix[i][N-l] = t;
        }
        ++l, --r;
    }
}