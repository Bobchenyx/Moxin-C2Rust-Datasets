typedef struct{
    int x;
    int y;
    int level;
}land;
int maxDistance(int** grid, int gridSize, int* gridColSize){
    int line=gridSize, col=*gridColSize;
    land *queue=(land*)malloc(sizeof(land)*line*col);
    int move[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int front=0, rear=0, flag=0;
    int tx,ty,tl,xx,yy;
    int i,j;
    for(i=0;i<line;i++)
        for(j=0;j<col;j++)
            if(grid[i][j]==1){
                queue[rear].x=i;
                queue[rear].y=j;
                queue[rear++].level=0;
            }
    while(front!=rear){
        tx=queue[front].x;
        ty=queue[front].y;
        tl=queue[front++].level;
        for(i=0;i<4;i++){
            xx=tx + move[i][0];
            yy=ty + move[i][1];
            if(xx<0||xx>=line||yy<0||yy>=col)
                continue;
            if(grid[xx][yy]==0){
                flag=1;
                grid[xx][yy]=2;
                queue[rear].x=xx;
                queue[rear].y=yy;
                queue[rear++].level=tl+1;
            }
        }
    }
    return flag==1?tl:-1 ;
}