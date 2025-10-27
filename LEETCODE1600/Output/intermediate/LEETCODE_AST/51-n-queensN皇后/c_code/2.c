/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int isvalid(int *flag,int cur,int j){
    int i;
    for(i=0;i<cur;i++){
        if(flag[i]==j||abs(flag[i]-j)==abs(i-cur)){//判断是否与前cur行皇后冲突，即当前在cur+1行的皇后不能与其他皇后放在一条对角线上，也不能放在同一列上
            return 0;
        }
    }
    return 1;
}
void backtracking(int n,int cur,int *flag,char*** map,int* returnSize, int** returnColumnSizes){
    int i,j;
    if(cur==n){//所有皇后都放上，把这一组结果记录下来
        map[*returnSize]=(char**)malloc(sizeof(char*)*n);
        for(i=0;i<n;i++){
            map[*returnSize][i]=(char*)malloc(sizeof(char)*(n+1));
            for(j=0;j<n;j++){
                if(flag[i]==j){//flag[i]表示第i行的皇后在flag[i]列上
                    map[*returnSize][i][j]='Q';
                }else{
                    map[*returnSize][i][j]='.';
                }
            }
            map[*returnSize][i][j]='\0';
        }
        (*returnColumnSizes)[*returnSize]=n;//记录每一组的列数，其实这个变量是多余的，因为列数行数都是n
        (*returnSize)++;//记录组数
        return ;
    }
   for(j=0;j<n;j++){
        if(isvalid(flag,cur,j)){//当前列可以放，那么判断放置好后接下来的情况
            flag[cur]=j;
            backtracking(n,cur+1,flag,map,returnSize,returnColumnSizes);
        }
    }
    return;//在cur-1行已经放好的情况下，第cur行不管放在哪一列都不满足，return，表示当前路径结束，回溯到上一行重新防置
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    int * flag=(int*)malloc(sizeof(int)*(n+1));
    int i;
    char ***map=(char***)malloc(sizeof(char**)*1000);
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*1000);
    memset(flag,0,sizeof(flag));
    *returnSize=0;
    backtracking(n,0,flag,map,returnSize,returnColumnSizes);
    return map;
}