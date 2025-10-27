//动态规划的基本形式 f（i）=af（i）+bf（i-1）
//你有n阶的话，那么n-1跨一步到n阶，n-2跨2步，其他无法刚好得到n阶段那么方式为f（n）=f(n-1) +f(n-2); 
int climbStairs(int n){
    int ret_tmp[2];
    int ret =0;
    ret_tmp[0]=1;
    ret_tmp[1]=2;
    if(n < 3){
        ret = n;
    }
    else{
        for(int i=3;i<n+1;i++){
            ret =ret_tmp[0] + ret_tmp[1]; //不断往前增加
            ret_tmp[0] = ret_tmp[1] ;
            ret_tmp[1] = ret ;
           // printf("i=%d,ret=%d",i,ret);
        }

    }
    return ret ;   
}