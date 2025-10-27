int divide(int dividend, int divisor){
    int INTMAX = 2147483647;
    int INTMIN = -2147483648;
    long long remain=0;
    int sign;
    if((dividend>0&&divisor>0)||(dividend<0&&divisor<0))
    {
        sign=1;
    }
    if((dividend<0&&divisor>0)||(dividend>0&&divisor<0))
    {
        sign=-1;
    }
    if(divisor==1)
    {
        return dividend;
    }
    if(dividend==INTMIN&&divisor==-1)
    {
        return INTMAX;
    }
    if(dividend==0&&divisor!=0)
    {
        return 0;
    }
    if(divisor==0)
    {
        return INTMAX;
    }
    long long dividen=llabs((long long)dividend);
    long long diviso=llabs((long long)divisor);
    while(dividen>=diviso)
    {
        long long t=diviso,p=1;
        while(dividen>=(t<<1))//左移一位相当于乘了2倍，所以是用位运算代替了除法，每次商都乘2
        {
            t=t<<1;//相当于是t乘了2
            p=p<<1;//相当于是p乘了2
        }
        remain=remain+p;
        dividen=dividen-t;
    }
    return sign==1?remain:-remain;
}


    /*if(dividend==INTMIN&&divisor==-1)
    {
        return INTMAX;
    }
    if(dividend==0&&divisor!=0)
    {
        return 0;
    }
    if(divisor==0)
    {
        return INTMAX;
    }
    long long dividen=(long long)dividend;
    long long diviso=(long long)divisor;
    if(dividen>0&&diviso>0)
    {
        remain=dividen;
        while(remain>=diviso)
        {
            remain-=diviso;
            count1++;
        }
    }
    else if(dividen<0||diviso<0)
    {
        if(dividen<0&&diviso>0)
        {
            remain=-dividen;
            while(remain>=diviso)
            {
                remain-=diviso;
                count2--;
            }
        }
        else if(dividen>0&&diviso<0)
        {
            diviso=-diviso;
            remain=dividen;
            while(remain>=diviso)
            {
                remain-=diviso;
                count3--;
            }
        }
        else
        {
            dividen=-dividen;
            diviso=-diviso;
            remain=dividen;
            while(remain>=diviso)
            {
                remain-=diviso;
                count4++;
            }
        }
    }*/