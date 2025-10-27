int uniquePaths(int m, int n){
    int maxPaths = 0;
    //特殊情况
    if ((m == 0) || (n == 0)) {
        return 0;
    }

    //申请一个二维数组用来存在动态规划过程中产生的数据
    int** array = (int **)malloc(sizeof(int *) * n);
    memset(array, 0, sizeof(int *) * n);
    for (int k = 0; k < n; k++) {
        *(array + k) = (int *)malloc(sizeof(int) * m);
        memset(*(array + k), 0, sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //初始条件,第一横行和第一纵列都是1
            if ((i == 0) || (j == 0)) {
                *(*(array + i) + j) = 1;
            } else {
                //状态转移方程：到达第n行m列的路径数目等于到达第n-1行m列的路径数加上到达第n行m-1列的路径数（因为从这两个点再走一步就可以到达finish）
                *(*(array + i) + j) = *(*(array + i - 1) + j) + *(*(array + i) + j - 1);
            }    
        }
    }
    maxPaths = *(*(array + n - 1) + m - 1);

    for (int k = 0; k < n; k++) {
        free(*(array + k));
    }
    free(array);
    return maxPaths;

}