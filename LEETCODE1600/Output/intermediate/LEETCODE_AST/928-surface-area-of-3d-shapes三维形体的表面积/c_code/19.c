#define min(a,b) a<b?a:b
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int linkpoint=0,cubenum=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
                if(grid[i][j]!=0){
                        cubenum+=grid[i][j];
                            linkpoint+=grid[i][j]-1;
                            if(i==0 && j>0){
                                if(grid[i][j-1]!=0){
                                    linkpoint+=min(grid[i][j-1],grid[i][j]);
                                }
                            }
                            if(j==0 && i>0){
                                if(grid[i-1][j]!=0){
                                    linkpoint+=min(grid[i-1][j],grid[i][j]);
                                }
                            }
                            if(i>0 && j>0){
                                if(grid[i-1][j]!=0){
                                    linkpoint+=min(grid[i-1][j],grid[i][j]);
                                }                
                                if(grid[i][j-1]!=0){
                                    linkpoint+=min(grid[i][j-1],grid[i][j]);
                                }
                            }                
                    }                    
                }
                
    }
    return cubenum*6-linkpoint*2;
}