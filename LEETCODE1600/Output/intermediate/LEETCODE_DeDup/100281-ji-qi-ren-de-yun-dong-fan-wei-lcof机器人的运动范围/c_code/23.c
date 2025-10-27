int movingCount(int m, int n, int k){
    int i, j, sum_i=0, sum_j=0, res=0, res_old=0;
    int flag[m][n];
    for(i=0; i<m; i++){
        // 计算横坐标的和
        if(i%10 == 0){
            sum_i = i/10;
        }else{
            sum_i++;
        }
        for(j=0; j<n; j++){
            // 计算纵坐标的和
            if(j%10 == 0){
                sum_j = j/10;
            }else{
                sum_j++;
            }
            // 判断本格子的左边和上面格子是否被访问过, 并且本格子满足条件
            if((j==0 || j>0 && flag[i][j-1]==1 || i>0 && flag[i-1][j]==1) && sum_i+sum_j <= k){
                flag[i][j] = 1;
                res++;
            }else{
                flag[i][j] = 0;
            }
        }
        // 如果第i行没有满足条件的格子，则结束
        if(res != res_old){
            res_old = res;
        }else{
            break;
        }
    }
    return res;
}