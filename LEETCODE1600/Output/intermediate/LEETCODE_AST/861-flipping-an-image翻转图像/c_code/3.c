c []
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = ASize;
    returnColumnSizes[0] = AColSize;  // 直接赋值
    for (int row = 0; row < ASize; row++) {
        for (int col = 0; col < (AColSize[row] + 1) / 2; col++) {  // 反转一半
            // 只有相同的才反转，因为不同刚好位置颠倒,因此相同的就是一样结果
            if (A[row][col] == A[row][AColSize[row] - 1 - col]) {
                A[row][col] = A[row][AColSize[row] - 1 - col] = 1 - A[row][col];  // 相反操作
            }
        }
    }
    return A;
}