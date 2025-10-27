//int test=2;
typedef struct MYQUEUE_NODE{
    int x;
    int y;
    int rotTime;
    struct MYQUEUE_NODE *next;
}MyQueueNode;

MyQueueNode *front,*rear;

void mq_insert(int,int,int);
MyQueueNode *mq_delete(void);
bool mq_is_empty(void);

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    //printf("%d %d\n",gridSize,*gridColSize);
    int ans=0;
    int rowSize=*gridColSize;
    int colSize=gridSize;
  //  grid[0][0]=0;
 //   grid[0][1]=2;
  //  int rowSize=2;
  //  int colSize=1;
    for(int i=0;i<colSize;i++)
    {
        for(int j=0;j<rowSize;j++)
        {
           // printf("%d ",grid[i][j]);
           if(grid[i][j]==2) //找到原始烂橘子放入队列，rottime=0
           {
               mq_insert(i,j,0);
           }
        }
        //printf("\n");
    }
    MyQueueNode *rotOrange;
    int i,j,t;
    while(!mq_is_empty())
    {
        rotOrange=mq_delete(); //取出烂橘子
        i=rotOrange->x;
        j=rotOrange->y;
        t=rotOrange->rotTime;
        //printf("out:%d %d %d\n",i,j,t);
        //向四周传染
        if(i>0)//up
        {
            if(grid[i-1][j]==1)
            {
                grid[i-1][j]=2+t+1;
                mq_insert(i-1,j,t+1);
            }
        }
        if(i+1<colSize)//down
        {
            if(grid[i+1][j]==1)
            {
                grid[i+1][j]=2+t+1;
                mq_insert(i+1,j,t+1);
            }
        }
        if(j>0)//left
        {
            if(grid[i][j-1]==1)
            {
                grid[i][j-1]=2+t+1;
                mq_insert(i,j-1,t+1);
            }
        }
        if(j+1<rowSize)//right
        {
            if(grid[i][j+1]==1)
            {
                grid[i][j+1]=2+t+1;
                mq_insert(i,j+1,t+1);
            }            
        }
    }

    //清理所有橘子
    for(int i=0;i<colSize;i++)
    {
        for(int j=0;j<rowSize;j++)
        {
            if(grid[i][j]==1)
            {
                return -1;
            }
            else if(grid[i][j]>2)
            {
                ans=ans>(grid[i][j]-2)?ans:(grid[i][j]-2);
            }
        }
    }

    return ans;
     /*
    printf("%dxxxxxxx",test);
    return 0;
   */
}

void mq_insert(int i,int j,int rt)
{
   // printf("in:%d %d %d\n",i,j,rt);
    MyQueueNode *new_node;
    new_node=(MyQueueNode *)malloc(sizeof(MyQueueNode));
    new_node->x=i;
    new_node->y=j;
    new_node->rotTime=rt;
    new_node->next=NULL; //因为是加到尾巴所以next一定是NULL
    //printf("%d %d %d\n",new_node->x,new_node->y,new_node->rotTime);
    if(rear==NULL)
    {
        front=rear=new_node;
    }
    else
    {
        rear->next=new_node;
        rear=new_node;
    }
}

MyQueueNode *mq_delete(void)
{
    MyQueueNode *tmp;
    tmp=front;
    front=front->next;
    if(front==NULL)
    {
        rear=NULL;
    }
    return tmp;
}

bool mq_is_empty(void)
{
    if(front==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}