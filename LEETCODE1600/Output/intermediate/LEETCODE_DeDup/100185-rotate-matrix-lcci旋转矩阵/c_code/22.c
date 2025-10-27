void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int row, col, diagonal;
    int i ,j;
    int tmp;

    row = matrixSize;
    col = *matrixColSize;
    diagonal = sqrt(row * row + col * col) * 0.5 + 0.5;

    // 沿对角线
    // x => col-1-y
    // y => x
    // 替换4次为一圈, 回到 (x,y)
    for (i = 0; i < diagonal; i++)
    {
        for(j = i; j < col-i-1; j++)
        {
            tmp = matrix[i][j];
            // (i,j) = (col-1-j, i)
            matrix[i][j] = matrix[col - j - 1][i];
            // (col-1-j, i) = (col-1-i, col-1-j)
            matrix[col - j - 1][i] = matrix[col - i - 1][col - j - 1];
            // (col-1-i, col-1-j) = (col-1-(col-1-j), col-1-i) = (j, col-1-i)
            matrix[col - i - 1][col - j - 1] = matrix[j][col - i - 1];
            // (j, col-1-i) = (col-1-(col-1-i), j) = (i,j) = tmp
            matrix[j][col - i - 1] = tmp;
        }
    }
}