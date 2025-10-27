void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int a[matrixSize];
    int i = 0;
    for(i=0; i<matrixSize/2; i++){//第i层
        for(int k=0; k<matrixSize-2*i; k++){
            a[k] = matrix[i][matrixSize-k-1-i];//a=上边列
        }
        for(int k=0; k<matrixSize-2*i; k++){
            matrix[i][matrixSize-k-1-i] = matrix[i+k][i];//上边列=左
        }
        for(int k=0; k<matrixSize-2*i; k++){
            matrix[i+k][i] = matrix[matrixSize-1-i][k+i];//左边列=下
        }
        for(int k=0; k<matrixSize-2*i; k++){
            matrix[matrixSize-1-i][k+i] = matrix[matrixSize-1-k-i][matrixSize-1-i];//下边列=右
        }
        for(int k=0; k<matrixSize-2*i; k++){
            matrix[matrixSize-1-k-i][matrixSize-1-i] = a[k];//右边列=a
        }
    }
}