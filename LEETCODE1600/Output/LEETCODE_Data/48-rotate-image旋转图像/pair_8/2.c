void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int temp;
    int i,j;
    for (i = 0; i < matrixSize; ++i)
        for (j = 0; j < matrixSize; ++j)
        {
            if(i<=j)
                break;
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }

    int index;
    for (i = 0; i < matrixSize; ++i)
    {
        index  = matrixSize-1;
        for (j = 0; j < matrixSize/2; ++j)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][index];
            matrix[i][index--] = temp;
        }
    }
}