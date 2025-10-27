void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int* nums=(int*)malloc(sizeof(int)*(matrixSize*matrixSize));
    int k=0;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=matrixSize-1;j>=0;j--)
        {
            nums[k++]=matrix[j][i];
        }
    }
    int t=0;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<matrixSize;j++)
        {
            matrix[i][j]=nums[t++];
        }
    }
    *matrixColSize=matrixSize;
}