void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i=0,j=0,t=0;
    while( i < matrixSize ){
        j = i+1;
        while( j <matrixSize ){
            t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
            j++;
        }
        i++;
    }
    i = 0;
    while( i < matrixSize ){
        j = 0;
        while( j < matrixSize / 2 ){
            t = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1] = t;
            j++;
        }
        i++;
    }
}