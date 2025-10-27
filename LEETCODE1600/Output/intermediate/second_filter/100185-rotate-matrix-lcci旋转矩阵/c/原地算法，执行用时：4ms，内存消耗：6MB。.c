void rotate(int** matrix, int matrixSize, int* matrixColSize){
  
     int temp=0;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=i;j<*matrixColSize;j++)
        {
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    for(int i=0;i<matrixSize;i++)
    {
        jiaohuan(matrix[i],*matrixColSize,0,*matrixColSize-1);
    }
    
    
}
void jiaohuan(int* arr,int length,int i,int j)
{
    int temp=0;
    while(i<j)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    
}