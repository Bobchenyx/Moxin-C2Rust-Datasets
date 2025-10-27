int projectionArea(int** grid, int gridSize, int* gridColSize){
        int i,j,xy=0,xz=0,yz=0,cmax,rmax,col=*gridColSize;
        for(j=0;j<col;j++){
            cmax=0;
            rmax=0;
            for(i=0;i<col;i++){
                 if(grid[i][j]>cmax)cmax=grid[i][j];
                 if(grid[j][i]>rmax)rmax=grid[j][i];
                 if(grid[i][j]!=0)xy++;
                    }
            xz+=cmax;
            yz+=rmax ;   
        }
        
    return xy+yz+xz;    
}