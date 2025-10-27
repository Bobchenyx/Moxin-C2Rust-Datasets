int climbStairs(int n){
    int methods[n+1];
    int i;
    methods[1] = 1;
    if(n >= 2)
        methods[2] = 2;
    for(i = 3;i <= n;i++){
        methods[i] = methods[i-1]+methods[i-2];
    }
    return methods[n];
}