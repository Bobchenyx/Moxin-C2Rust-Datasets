void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int i, j, starti, startj, m, prev;
    if (matrix == 0 || matrixSize == 0 || matrixColSize == 0) {
        return 0;
    }
    for (i = 0; i < matrixSize / 2; i++) {
        starti = i;
        startj = i;
        int tmp;
        for (m = 0; m < matrixSize - 2 * i - 1; m++) {
            prev = matrix[starti + 1][startj];
            for (j = 0; j < matrixSize - 2 * i; j++) {
                tmp = matrix[starti][startj + j];
                matrix[starti][startj + j] = prev;
                prev = tmp;
            }
            for (j = 1; j < matrixSize - 2 * i - 1; j++) {
                tmp = matrix[starti + j][matrixSize - 1 - startj];
                matrix[starti + j][matrixSize - 1 - startj] = prev;
                prev = tmp;
            }
            for (j = 0; j < matrixSize - 2 * i; j++) {
                tmp = matrix[matrixSize - 1 - starti][matrixSize - 1 - startj - j];
                matrix[matrixSize - 1 - starti][matrixSize - 1 - startj - j] = prev;
                prev = tmp;
            }
            for (j = 1; j < matrixSize - 2 * i - 1; j++) {
                tmp = matrix[matrixSize - 1 - starti - j][startj];
                matrix[matrixSize - 1 - starti - j][startj] = prev;
                prev = tmp;
            }
        }
    }
}