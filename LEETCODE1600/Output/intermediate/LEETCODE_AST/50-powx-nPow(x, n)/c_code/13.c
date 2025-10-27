C []
/* 实现 pow(x, n) ，即计算 x 的 n 次幂函数 */
/* 分治法,尾递归,O(logn) */
double powHelper(double x, int n, double re)
{
    if (n == 0)
        return 1 * re;
    else if (n == 1)
        return x * re;
    else
        return n % 2 == 0 ? powHelper(x * x, n / 2, re) : powHelper(x * x, n / 2, x * re);
}

double myPow(double x, int n)
{
    if (n < 0)
        x = 1 / x;
    return n % 2 == 0 ? powHelper(x * x, n / 2, 1) : powHelper(x * x, n / 2, x);
}