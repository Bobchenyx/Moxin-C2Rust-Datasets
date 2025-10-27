int a[100][100]={0};
int uniquePaths(int m, int n){

    if(m==1){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(a[m-1][n-1] == 0){
        a[m-1][n-1]=uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
    
    return a[m-1][n-1];

}