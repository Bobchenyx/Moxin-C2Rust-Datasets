void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    void swap(int *, int *);
    int heigh = (matrixSize + 1)/2;
    int wide = matrixSize/2;
    for(int i = 0; i < heigh; i++)
    {
        for(int j = 0; j < wide; j++)
        {
            swap(&matrix[i][j], &matrix[j][matrixSize - i - 1]);
            swap(&matrix[i][j], &matrix[matrixSize - i - 1][matrixSize - j - 1]);
            swap(&matrix[i][j], &matrix[matrixSize - j - 1][i]);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}