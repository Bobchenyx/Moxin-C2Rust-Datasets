int climbStairs(int n){
    if(n < 0)
        return -1;
    
    int *res = malloc(sizeof(int)* (n+1));
    res[0] = 1;
    res[1] = 2;
    for (size_t i = 2; i < n; i++)
    {
        res[i] = res[i-1] + res[i-2];
    }
    return res[n-1]; 
}