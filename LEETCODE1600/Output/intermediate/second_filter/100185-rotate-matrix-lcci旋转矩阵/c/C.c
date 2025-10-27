void rotate(int** matrix, int matrixSize, int* matrixColSize){
    
    int i, j;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < i; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
            //printf("%d %d\n", matrix[i][j], matrix[j][i]);
        }
        
    }

    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixSize / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = temp;
        }
    }

}