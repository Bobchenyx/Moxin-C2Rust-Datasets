void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int pre,temprow,tempcol;
    int visited[matrixSize][matrixSize];
    for(int i=0;i<matrixSize;i++)
        for(int j=0;j<matrixSize;j++)
            visited[i][j]=0;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<matrixSize;j++)
        {
            if(visited[i][j]==0)
            {
                
            pre=matrix[i][j];
            for(int k=0;k<4;k++)
            {
                visited[i][j]=1;
                temprow=j;
                tempcol=matrixSize-1-i;
                i=temprow;
                j=tempcol;
                int temp=pre;
                pre=matrix[i][j];
                matrix[i][j]=temp;
            }
            }
        }
    }
}