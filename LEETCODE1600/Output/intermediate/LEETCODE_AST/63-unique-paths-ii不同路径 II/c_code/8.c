int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    long *arr = (long *)malloc(sizeof(long) *(obstacleGridColSize[0]+1));
    memset(arr,0,sizeof(long) *(obstacleGridColSize[0]+1));
    arr[1] = 1;

    for(int j=1;j<=obstacleGridSize;j++)
        for(int k=1;k<=obstacleGridColSize[j-1];k++)
            if (obstacleGrid[j-1][k-1]==1)arr[k] = 0;
            else arr[k] += arr[k-1];
    return arr[*obstacleGridColSize];
}