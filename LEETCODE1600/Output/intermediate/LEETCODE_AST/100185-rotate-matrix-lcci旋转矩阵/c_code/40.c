void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
  /*int temp,w,h;
  const int N = matrixColSize[0] - 1;
 
  for(int i = 0;i <= N/2; ++i)
  {
      for(int j = 0;j < (N+1)/2; ++j)
      {
          temp = matrix[i][j];
          matrix[i][j] = matrix[N-j-1][i];//matrix[i][j] = matrix[N+1-j][i];
          matrix[N-j-1][i] = matrix[N-i-1][N-j-1];// matrix[N+1-j][i] = matrix[N+1-i][N+1-j];
          matrix[N-i-1][N-j-1] = matrix[j][N-i-1];//matrix[N+1-i][N+1-j] = matrix[j][N+1-i];
          matrix[j][N-i-1] = temp;//matrix[j][N+1-i] = temp;
      }
  }*/

    
    int temp;
   
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i; j < matrixSize; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - j - 1];
            matrix[i][matrixSize - j - 1] = temp;
        }
    }


}