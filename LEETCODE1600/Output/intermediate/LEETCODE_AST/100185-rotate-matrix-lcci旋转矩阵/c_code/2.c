void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for(int i=0; i < matrixSize / 2; i++){
		int ni = matrixSize-1-i;
        for(int j=i; j < ni; j++){
			int nj = matrixSize-1-j;
            int temp = matrix[i][j];
            matrix[i][j] = matrix[nj][i];
            matrix[nj][i] = matrix[ni][nj];
            matrix[ni][nj] = matrix[j][ni];
            matrix[j][ni] = temp;
        }
    }
}