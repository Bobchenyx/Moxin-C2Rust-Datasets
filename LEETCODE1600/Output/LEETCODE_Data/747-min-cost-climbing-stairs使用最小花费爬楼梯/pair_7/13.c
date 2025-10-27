int minCostClimbingStairs(int* cost, int costSize){
    int stage0=cost[0];
    int stage1=cost[1];
    int i=2;
    while(i<costSize){
        int temp=(stage0<stage1)?stage0+cost[i]:stage1+cost[i];
        stage0=stage1;
        stage1=temp;
        i++;
    }
    return stage0<stage1?stage0:stage1;
}