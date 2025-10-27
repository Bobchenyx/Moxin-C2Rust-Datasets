void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if (!matrix || matrixSize == 0 || !matrixColSize || matrixColSize[0] == 0) return;

    int temp[matrixSize];
    int left = 0;
    int right = matrixSize-1;

    while (left < right) {
        for (int i = 0; i < right - left + 1; i++) temp[i] = matrix[left][i+left];
        for (int i = 0; i < right - left + 1; i++) matrix[left][right-i] = matrix[i+left][left];
        for (int i = 0; i < right - left + 1; i++) matrix[i+left][left] = matrix[right][i+left];
        for (int i = 0; i < right - left + 1; i++) matrix[right][i+left] = matrix[right-i][right];
        for (int i = 0; i < right - left + 1; i++) matrix[i+left][right] = temp[i];

        left++;
        right--;
    }
}