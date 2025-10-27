int minCostClimbingStairs(int* cost, int costSize){
    int* result=(int*)malloc(sizeof(int)*costSize);
    result[0]=0;
    result[1]=cost[0]<cost[1]?cost[0]:cost[1];
    for(int i=2;i<costSize;++i)
        result[i]=  result[i-1]+cost[i] < result[i-2]+cost[i-1] ?
                    result[i-1]+cost[i] : result[i-2]+cost[i-1];
    int n=result[costSize-1];
    free(result);
    return n;
}