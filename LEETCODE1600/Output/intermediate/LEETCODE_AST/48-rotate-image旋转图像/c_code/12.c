void exchangeRow(int** matrix, int matrixSize)//将矩阵的第i行和第matrixSize-i行互换(0<=i<matrixSize)
{
    int *tmp = malloc(sizeof(int) * matrixSize);
    for(int i = 0, j = matrixSize-1; i < j; ++i, --j) {
        tmp = matrix[i];
        matrix[i] = matrix[j];
        matrix[j] = tmp;
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    exchangeRow(matrix,matrixSize);
    for(int i = 0; i < matrixSize; ++i)//转置
        for(int j = i; j < matrixSize; ++j){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
}