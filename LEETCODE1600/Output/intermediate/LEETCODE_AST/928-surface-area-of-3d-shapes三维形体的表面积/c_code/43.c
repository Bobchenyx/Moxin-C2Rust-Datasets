#define MIN(a,b) (a>b?b:a)
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j,sum=0;
    if(gridSize==0||*gridColSize==0) return 0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<*gridColSize;j++){
            sum=sum+6*grid[i][j];
            if(i!=gridSize-1){//处理并列重叠
                sum=sum-2*MIN(grid[i][j],grid[i+1][j]);//前一行与后一行重叠 1,3重叠1。2,3重叠2
            }
            if(j!=*gridColSize-1){//处理并行重叠
                sum=sum-2*MIN(grid[i][j],grid[i][j+1]);//前一列与后一列重叠 1,3重叠1。2,3重叠2
            }
            if(grid[i][j]>1){//处理上下重叠 
                sum=sum-2*(grid[i][j]-1);//2层重叠2-1层,3层重叠3-1层  
            }         
        }
    }
    return sum;
}