int climbStairs(int n){
    int a0, a1, a2;
    
    if (n == 1)
    {
        return 1;
    }

    if(n == 2)
    {
        return 2;
    }

    a0 = 1;
    a1 = 2;
    n -= 2;

    while(n)
    {
        a2 = a0 + a1;
        a0 = a1; 
        a1 = a2;
        n--;
    }

    return a2;
}