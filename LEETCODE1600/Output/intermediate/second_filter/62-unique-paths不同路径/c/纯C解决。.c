int uniquePaths(int m, int n){
    if(m==0||n==0)
    return 0;
    //path[i][j]记录通往元素nums[i][j]的路径数
    int **path=(int **)malloc(sizeof(int *)*n);//一共有n行
    int i,j;
    for(i=0;i<n;i++)
    path[i]=(int *)malloc(sizeof(int)*m);//一共有m列
    //初始化
    for(i=0;i<n;i++)
    path[i][0]=1;
    for(j=0;j<m;j++)
    path[0][j]=1;
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
        path[i][j]=path[i-1][j]+path[i][j-1];
    return path[n-1][m-1];
}