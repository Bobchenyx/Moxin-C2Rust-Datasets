#define SWAP(a,b) do{a^=b;b^=a;a^=b;}while(0)

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    // 对角线翻转
    for (i=0; i < *matrixColSize; i++){
        for (j=i+1; j < *matrixColSize; j++)
            SWAP(matrix[i][j], matrix[j][i]);
    }
    // 水平线翻转
    for (i=0; i < *matrixColSize; i++){
        for (j=0; j < *matrixColSize / 2; j++)
            SWAP(matrix[i][j], matrix[i][*matrixColSize - 1 - j]);
    }
}