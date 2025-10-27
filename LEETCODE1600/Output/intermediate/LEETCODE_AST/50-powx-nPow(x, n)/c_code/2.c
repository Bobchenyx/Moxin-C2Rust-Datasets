static double _pow(double x, long n)
{
    if (0 == n)
    {
        return 1.0;
    }

    if (1 == n)
    {
        return x;
    }

    double tmp = _pow(x, n / 2);
    return n & 1 ? tmp * tmp * x : tmp * tmp;
}

double myPow(double x, int n){
    return n < 0 ? 1.0 / _pow(x, -(long)n) : _pow(x, n);
}