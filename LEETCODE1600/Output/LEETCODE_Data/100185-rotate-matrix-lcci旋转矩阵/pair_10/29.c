void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int low=0,high=matrixSize-1;
    while(low<high)
    {
        int* temp=matrix[low];
        matrix[low]=matrix[high];
        matrix[high]=temp;
        ++low;--high;
    }
   for(int i=0;i<matrixSize;++i)
        for(int j=0;j<i;++j)
            {
                 int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
}