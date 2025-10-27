#define min(a,b) a<b?a:b
int minCostClimbingStairs(int* cost, int costSize){
    if(costSize<=1)
        return 0;
    int* result=(int*)malloc((costSize+1)*sizeof(int));
    result[1]=result[0]=0;
    for(int i=2;i<costSize+1;i++){
        result[i]=min(result[i-2]+cost[i-2],result[i-1]+cost[i-1]);
    }
    return result[costSize];
}