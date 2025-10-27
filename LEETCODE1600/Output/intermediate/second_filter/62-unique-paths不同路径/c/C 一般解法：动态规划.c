int uniquePaths(int m, int n){

    int **arr = (int **)malloc(sizeof(int*) *n);
    int i,v;
    for(i=0;i<n;i++){
        arr[i] = (int *)malloc(sizeof(int) *m);
        for(v=0;v<m;v++)
            if(i==0||v==0) arr[i][v] = 1;
            else arr[i][v] = arr[i-1][v] + arr[i][v-1];
    }
    return arr[n-1][m-1];
}