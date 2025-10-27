int min(int a,int b)
{
    if(a<b)
    return a;
    return b;
}
int minCostClimbingStairs(int* cost, int costSize){
    int mark[costSize];
    memset(mark,0,sizeof(int)*costSize);
    mark[0]=cost[0];
    mark[1]=cost[1];
    int i;
    for(i=2;i<costSize;i++)
    {
        mark[i]=min(mark[i-1],mark[i-2])+cost[i];
    }
    if(mark[costSize-1]<mark[costSize-2])
    return mark[costSize-1];
    return mark[costSize-2];
}