void step(int n,int *result){
    if(n>1){
        step(n-2,result);
        step(n-1,result);
    }else if(n>0){
        step(n-1,result);
    }else{
        (*result)++;
    }
}

int climbStairs(int n){
    int result;
    int *p = &result;
    step(n,p);
    return result;
}