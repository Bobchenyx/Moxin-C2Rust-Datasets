double myPow(double x, int n)
{
    long long b = n;//int型负数取反时会溢出
    if(b==0)
    return 1;
    if(b<0)
    {
        x = 1/x;
        b = b*(-1);
    }
    if(b==1)
    return x;
    if(b%2==0)
    {
        return myPow(x*x,b/2);
    }
    else
    return x*myPow(x*x,b/2);
}