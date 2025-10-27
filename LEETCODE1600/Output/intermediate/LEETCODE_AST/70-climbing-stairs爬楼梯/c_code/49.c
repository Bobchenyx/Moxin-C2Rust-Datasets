int climbStairs(int n)
{
    int Mark[65] = {0};
    return Sum(n,Mark);
}
int Sum(int n,int Mark[])
{
    int sum = 0;
    if (n == 0)
        return sum + 1;
    if (n < 0)
        return 0;
    if (Mark[n] != 0)
        sum = Mark[n];
    else
    {
        sum = Sum(n - 1,Mark) + Sum(n - 2,Mark);
        Mark[n] = sum;
    }
    return sum;
}