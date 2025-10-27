int divide(int dividend, int divisor){
    long cnt = 0;
    int tag = 1;

    if (dividend == 0)
    {
        return 0;
    }

    /*符号判断*/
    if ((dividend < 0 && divisor >0) || (dividend > 0 && divisor < 0))
    {
        tag = -1;

    }
    /*结果溢出判断*/
    if (dividend <= INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == 1)
    {
        return INT_MIN;
    }
    /*防止反转溢出*/
    long dend = dividend;
    long dor  = divisor;
    if (dividend < 0)
    {
        dend = -dend;
    }
    if (divisor < 0)
    {
        dor = -dor;
    }

    /*指数增长*/
    while (dor*(cnt+1) <= dend)
    {
        cnt = (2*cnt +1);
    }
    /*回退*/
    while (dor*cnt > dend)
    {
        cnt--;
    }

    return cnt*tag;

}