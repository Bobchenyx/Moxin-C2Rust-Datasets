/* 暴力搜索 */
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }
int maxArea(int* height, int heightSize){
    int res = 0;
    int i = 0, j = heightSize -1;
    while(i < j){
        res = max(res, (j - i)*min(height[i], height[j]));
        if(height[i] < height[j]) i++;
        else j--;
    }
    return res;
}


/* 贪心算法 */
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }
int maxArea(int* height, int heightSize){
    int res = 0;
    int i = 0, j = heightSize -1;
    while(i < j){
        res = max(res, (j - i)*min(height[i], height[j]));
        if(height[i] < height[j]) i++;
        else j--;
    }
    return res;
}


/* 动态规划 */
int min(int a, int b) { return a > b ? b : a;} 
int max(int a, int b, int c){
    int ans = 0;
    return (ans = a > b? a:b)> c ? ans:c;
}
int maxArea(int* height, int heightSize){
    int res = 0;
    int **dp = (int **)malloc(sizeof(int *)* heightSize);
    for(int i = 0; i < heightSize; i++){
        dp[i] = (int *)malloc(sizeof(int)*heightSize);
        memset(dp[i], 0, sizeof(dp[i]));
    }

    for(int j = 1; j < heightSize ;j++){
        for(int i = 0; i < j; i++){
            if(j - i == 1){
                dp[i][j] = min(height[i] , height[j]);
            } else{
                dp[i][j] = max((j - i)* min(height[i] , height[j]), dp[i + 1][j], dp[i][j-1]);
            }
            res = res > dp[i][j] ? res : dp[i][j];
        }
    }
    return res;
}