c []
void rotateSolver(int** matrix, int firstIndex, int n)
{
    if (n <= 1)
    {
        return;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        int tmp = matrix[firstIndex][firstIndex + i];
        matrix[firstIndex][firstIndex + i] = matrix[firstIndex + n - 1 - i][firstIndex];
        matrix[firstIndex + n - 1 - i][firstIndex] = matrix[firstIndex + n - 1][firstIndex + n - 1 - i];
        matrix[firstIndex + n - 1][firstIndex + n - 1 - i] = matrix[firstIndex + i][firstIndex + n - 1];
        matrix[firstIndex + i][firstIndex + n - 1] = tmp;
    }
    rotateSolver(matrix, firstIndex + 1, n - 2);
}



void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    rotateSolver(matrix, 0, matrixSize);
}