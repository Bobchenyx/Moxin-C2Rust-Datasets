#define MaxSize 100
void countMin(int** grid, int gridSize, int* gridColSize,int *stack_x,int *stack_y,int *stack_X,int *stack_Y,int top,int Top,int *count,int *orange)
{
    if(top==-1)//空栈
    return;
    int flag=0;
    int dir_y[4]={-1,0,0,1};//方向数组
    int dir_x[4]={0,-1,1,0};
    int i,j;
    int new_x,new_y;
    int pos_x,pos_y;
    for(top;top>=0;top--)
    {   
 
        pos_x=stack_x[top];
        pos_y=stack_y[top];
        for(j=0;j<4;j++)
        {
            new_x=pos_x+dir_x[j];
            new_y=pos_y+dir_y[j];
            if((new_x>=0&&new_x<gridSize)&&(new_y>=0&&new_y<*gridColSize))//在网格之内
                if(grid[new_x][new_y]==1)//可感染的入栈
                {
                //    printf("22222\n");
                    (*orange)--;
                    grid[new_x][new_y]=2;
                    flag=1;
                    stack_X[++Top]=new_x;
                    stack_Y[Top]=new_y;
                }
        }
        
    }
    if(flag==1)//若存在可感染的情况才能够加时间
    (*count)++;
    countMin(grid,gridSize,gridColSize,stack_X,stack_Y,stack_x,stack_y,Top,top,count,orange);
}
int orangesRotting(int** grid, int gridSize, int* gridColSize){//先行后列
int stack_x[MaxSize];//感染栈
int stack_y[MaxSize];
int stack_X[MaxSize];//待感染栈
int stack_Y[MaxSize];
int top=-1;
int Top=-1;
int count=0;
int orange=0;
int i,j;
    for(i=0;i<gridSize;i++)//行遍历
        for(j=0;j<*gridColSize;j++)//列遍历
        {
            if(grid[i][j]==2){//坏橘子入栈
            stack_x[++top]=i;
            stack_y[top]=j;
        }
        else if(grid[i][j]==1)
            orange++;
        }
    countMin(grid,gridSize,gridColSize,stack_x,stack_y,stack_X,stack_Y,top,Top,&count,&orange);
    if(orange==0)
    return count;
    return -1;
}