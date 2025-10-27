void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, temp, temp2;
    
    for (i = 0; i <= (matrixSize - 1)/2; i++) {
        for (j = i; j < matrixSize - 1 - i; j++) {
            temp = matrix[j][matrixSize-1-i];
            matrix[j][matrixSize-1-i] = matrix[i][j];
            temp2 = matrix[matrixSize-1-i][matrixSize-1-j];
            matrix[matrixSize-1-i][matrixSize-1-j] = temp;
            matrix[i][j] = matrix[matrixSize-1-j][i];
            matrix[matrixSize-1-j][i] = temp2;
        }
    }
}