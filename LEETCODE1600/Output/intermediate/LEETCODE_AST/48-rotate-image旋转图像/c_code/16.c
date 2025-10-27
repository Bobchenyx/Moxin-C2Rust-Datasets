void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0) return;
    int tmp;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < i; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < (*matrixColSize) / 2; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize- j - 1];
            matrix[i][matrixSize- j - 1] = tmp;
        }
    }
}