void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i;
    int j;     // 临时数组游标
    int x = 0; // 起始坐标

    int *tmp1 = (int*)malloc(sizeof(int) * (matrixSize - 1)); // 临时数组，下同
    int *tmp2 = (int*)malloc(sizeof(int) * (matrixSize - 1)); 

    while (matrixSize > 0) { // 因为是正方形矩阵，所以matrixSize == *matrixColSize，任取其一使用
        for (i = x, j = 0; i < matrixSize - 1; i++, j++) {
            tmp1[j] = matrix[i][matrixSize - 1]; // 保存被替换的元素，用于下次替换其他的元素
            matrix[i][matrixSize - 1] = matrix[x][i];
        }

        for (j = 0; i > x; i--, j++) {
            tmp2[j] = matrix[matrixSize - 1][i]; // 保存被替换的元素，用于接下来替换其他的元素
            matrix[matrixSize - 1][i] = tmp1[j]; // 用上次保存的元素替换目标元素
        }

        for (i = matrixSize - 1, j = 0; i > x; i--, j++) {
            tmp1[j] = matrix[i][x]; // 同上
            matrix[i][x] = tmp2[j];
        }

        for (j = 0; i < matrixSize - 1; i++, j++) {
            matrix[x][i] = tmp1[j];
        }

        x++; // 起始坐标递增，进入下一圈，因为是正方形矩阵，所以用一个变量表示就行
        matrixSize--;
    }
    free(tmp1);
    free(tmp2);
}