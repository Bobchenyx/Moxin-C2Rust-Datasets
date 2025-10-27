#define MAXNUM 101  // m 和 n 的值均不超过 100
#define INITPATH 1 // 初始步数

int uniquePaths(int m, int n){
    int dpPath[MAXNUM][MAXNUM] = {0};
    if((m >= MAXNUM) || (n >= MAXNUM)){ // 超过最大值
        return 0;
    }

    /* 题中是从左上角到右上角，这里做了一个坐标系转换，从左下角到右上角 */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == 0) && (j == 0)){ // 初始位置
                dpPath[i][j] = INITPATH;
                continue;
            }
            if (i == 0) { //这里第一行上的移动，只有一个方向
                dpPath[i][j] = dpPath[i][j - 1];
                continue;
            }
            if (j == 0) { //这里第一列上的移动，只有一个方向
                dpPath[i][j] = dpPath[i - 1][j];
                continue;
            }
            dpPath[i][j] = dpPath[i - 1][j] + dpPath[i][j - 1]; // 通常两个方向
        }
    }
    return dpPath[n - 1][m -1];
}