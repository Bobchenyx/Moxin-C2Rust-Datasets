//思路：先选中一个元素，计算出它旋转后应该属于的位置
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize<=1) return;
    int mid=matrixSize/2-1;
    for(int m=0;m<=mid;++m)
        for(int n=m;n<matrixSize-1-m;++n)
        {
            int temp=matrix[m][n];
            matrix[m][n]=matrix[matrixSize-1-n][m];//左上角
            matrix[matrixSize-1-n][m]=matrix[matrixSize-1-m][matrixSize-1-n];//左下
            matrix[matrixSize-1-m][matrixSize-1-n]=matrix[n][matrixSize-1-m];
            matrix[n][matrixSize-1-m]=temp;//右上角
        }
}