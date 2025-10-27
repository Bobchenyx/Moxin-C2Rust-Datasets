int cmn(int m ,int n)
{
    long int ret =1;
    for(int i=1;i<=n;i++){
        ret *=(m-i+1);
        ret /=i;
    }
    return ret;
}
int uniquePaths(int m, int n){
    int ret = 0;
    if((n <=1)||(m<=1))
        return 1;
    if(n<m)
        ret =cmn(m+n-2 ,n-1);//选计算方式少的一种
    else    
        ret =cmn(m+n-2 ,m-1); 
    return ret ;
}