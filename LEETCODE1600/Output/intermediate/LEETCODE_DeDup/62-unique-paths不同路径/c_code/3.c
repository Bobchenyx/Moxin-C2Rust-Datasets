void recursion(int m,int n,int i,int j,int* result){
    if(i<m){
        recursion(m,n,i+1,j,result);
    }
    if(j<n){
        recursion(m,n,i,j+1,result);
    }
    if(i==m && j==n){
        (*result)++;
    }
}

int uniquePaths(int m, int n){
    int result;
    recursion(m,n,1,1,&result);
    return result;
}