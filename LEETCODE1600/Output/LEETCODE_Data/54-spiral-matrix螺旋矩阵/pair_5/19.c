/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0; return 0;
    }
    *returnSize = matrixSize * (*matrixColSize);
    int* ans = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0, j = -1, num = 0, level = 0;
    while (num < *returnSize) {
        while (j < (*matrixColSize) - 1 - level) ans[num++] = matrix[i][++j];
        while (i < matrixSize - 1 - level) ans[num++] = matrix[++i][j];
        if (num == *returnSize) break;
        while (j > level) ans[num++] = matrix[i][--j];
        level++;
        while (i > level) ans[num++] = matrix[--i][j];
    }
    return ans;
}