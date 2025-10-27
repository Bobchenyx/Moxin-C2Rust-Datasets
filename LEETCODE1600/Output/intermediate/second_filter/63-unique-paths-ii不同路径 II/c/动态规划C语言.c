#define INITPATH 1
#define MAXNUM 100
#define PRINTF //printf
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    long dpPath[MAXNUM][MAXNUM] = {0};
    int maxRow = (obstacleGridSize - 1); // 行数
    int maxCcol = (obstacleGridColSize[0] - 1); // 列数是一样的
    PRINTF("maxRow:%d maxCcol:%d\n",maxRow, maxCcol);
    if((maxRow < 0) || (maxRow > MAXNUM)){ // 无效列数
        return 0;
    }
    if((maxCcol < 0) || (maxCcol > MAXNUM)){ // 无效行数
        return 0;
    }
    for (int i = 0; i <= maxRow; i++) {
        for (int j = 0; j <= maxCcol; j++) {
            if (obstacleGrid[i][j] == 1) { // 障碍物优先级最高
                dpPath[i][j] = 0;
                continue;
            }
            if ((i == 0) && (j == 0)) { // 起始位置出去
                dpPath[i][j] = 1;
                continue;
            }
            if (i == 0) { // 最上一行，只有向右一个方向
                dpPath[i][j] = dpPath[i][j - 1];
                continue;
            }
            if (j == 0) { // 最左一列，只有向下一个方向
                dpPath[i][j] = dpPath[i - 1][j];
                continue;
            }
            if(dpPath[i - 1][j] > INT_MAX - dpPath[i][j - 1]){
                PRINTF("%d %d %d %d %d %d\n",obstacleGrid[i][j],i,j, dpPath[i][j], dpPath[i - 1][j], dpPath[i][j - 1]);
            }
            dpPath[i][j] = dpPath[i - 1][j] + dpPath[i][j - 1]; //正常是两个方向，向右或者向上（坐标系翻转了）
        }
    }
    return dpPath[maxRow][maxCcol];

}