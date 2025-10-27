//-----------------------------------------------------------------记录：当前位置，参照的大陆位置
typedef struct Set{
    int x;
    int y;
    int fromX;
    int fromY;
}Set;
Set* newSet(int X,int Y,int FromX,int FromY)
{
    Set* s=(Set*)malloc(sizeof(Set));
    s->x=X;
    s->y=Y;
    s->fromX=FromX;
    s->fromY=FromY;
    return s;
} 
//-----------------------------------------------------------------链表队列，BFS用
typedef struct Node{
    Set* data;
    struct Node* next;
}Node;
Node* newNode(Set* Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
Node* queuePush(Node* Rear,Set* S)
{
    Node* n=newNode(S);
    n->next=Rear->next;
    Rear->next=n;
    return n;
    //不能Rear==Rear->next
    //因为形参是值传递，不会改变实参的值
    //所以返回最后一个节点的地址
    //入栈操作是 rear=queuePush(rear,s);
}
Set* queuePop(Node* Head,Node** RearAddress)
{
    if(Head->next==*RearAddress)
        *RearAddress=Head;
    Node* n=Head->next;
    Head->next=n->next;
    Set* result=n->data;
    free(n);
    return result;
}
void queueDel(Node* Head)
{
    while(Head!=0)
    {
        Node* n=Head;
        Head=Head->next;
        free(n->data);
        free(n);
    }
}
//-----------------------------------------------------------------更新最远距离
int updata(int Max,Set* S)
{
    int xDistance = S->x > S->fromX ? S->x - S->fromX : S->fromX - S->x;
    int yDistance = S->y > S->fromY ? S->y - S->fromY : S->fromY - S->y;
    return Max > xDistance+yDistance ? Max : xDistance+yDistance; 
}
//-----------------------------------------------------------------解答
int maxDistance(int** grid, int gridSize, int* gridColSize){
    //建队列
    Node* queueHead=newNode(0);
    Node* queueRear=queueHead;
    //把大陆先入队，同时查看是不是只有大陆或者只有海洋
    int allOcean=1,allLand=1;
    for(int i=0;i<gridSize;++i)
        for(int j=0;j<gridColSize[i];++j)
            if(grid[i][j]==1)
                {
                    Set* s=newSet(i,j,i,j);
                    queueRear=queuePush(queueRear,s);
                    allOcean=0;
                }
            else
                allLand=0;       
    if(allLand||allOcean)
    {
        queueDel(queueHead);
        return -1;
    }
    //BFS
    int max=0;
    while(queueHead!=queueRear)
    {
        Set* s=queuePop(queueHead,&queueRear);
        if(s->y+1<gridColSize[s->x] && grid[s->x][s->y+1]==0)
        {
            Set* temp=newSet(s->x,s->y+1,s->fromX,s->fromY);
            max=updata(max,temp);
            grid[temp->x][temp->y]=1;
            queueRear=queuePush(queueRear,temp);
        }
        if(s->x+1<gridSize && grid[s->x+1][s->y]==0)
        {
            Set* temp=newSet(s->x+1,s->y,s->fromX,s->fromY);
            max=updata(max,temp);
            grid[temp->x][temp->y]=1;
            queueRear=queuePush(queueRear,temp);
        }
        if(s->y-1>=0 && grid[s->x][s->y-1]==0)
        {
            Set* temp=newSet(s->x,s->y-1,s->fromX,s->fromY);
            max=updata(max,temp);
            grid[temp->x][temp->y]=1;
            queueRear=queuePush(queueRear,temp);
        }
        if(s->x-1>=0 && grid[s->x-1][s->y]==0)
        {
            Set* temp=newSet(s->x-1,s->y,s->fromX,s->fromY);
            max=updata(max,temp);
            grid[temp->x][temp->y]=1;
            queueRear=queuePush(queueRear,temp);
        }
        free(s);
    }
    queueDel(queueHead);
    return max;
}