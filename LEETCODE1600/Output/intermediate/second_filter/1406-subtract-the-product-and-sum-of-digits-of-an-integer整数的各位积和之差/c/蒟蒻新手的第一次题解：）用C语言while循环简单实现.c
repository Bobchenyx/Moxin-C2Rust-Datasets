int subtractProductAndSum(int n){
    int i, j, mul = 1, sum = 0;
    i = n;
    j = n;
    while(i)
    {
        mul *= (i % 10);
        i /= 10;
    }
    while(j)
    {
        sum += (j %10);
        j /= 10; 
    }
    return mul - sum;

}