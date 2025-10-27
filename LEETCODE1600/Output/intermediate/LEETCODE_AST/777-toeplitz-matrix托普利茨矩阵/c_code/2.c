bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    int M = matrixSize;
    int N = matrixColSize[0];
    for(i=0, j=0; j<N-1; j++){ //检索右上三角
        int temp = matrix[i][j]; //依次检索第一行的数
        int a = i+1, b = j+1;
        while(a<M && b<N){
            if(matrix[a][b] != temp)
            return false;
            a++;
            b++;
        }
    }
    for(i=1, j=0; i<M-1; i++){ //检索左下三角
        int temp = matrix[i][j]; //依次检索第一列的数
        int a = i+1, b = j+1;
        while(a<M && b<N){
            if(matrix[a][b] != temp)
            return false;
            a++;
            b++;
        }
    }
    return true;
}