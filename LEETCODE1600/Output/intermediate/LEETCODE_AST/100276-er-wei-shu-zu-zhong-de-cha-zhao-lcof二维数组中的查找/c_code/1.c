bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    
    
    if(matrixSize==0)
    return false;
    
    int col=*matrixColSize;
    int row=matrixSize;
    int counter1=1;//计数器，标记删除了几列


    for(int i=0;i<row;i++)//行循环
    {

        for(int j=col-counter1;j>=0;j--)//列循环
        {
            if(matrix[i][j]>target)//删除列
                counter1++;
            else if(matrix[i][j]<target)//删除行
                break;
            else return true;

        }
    }

    return false;

}