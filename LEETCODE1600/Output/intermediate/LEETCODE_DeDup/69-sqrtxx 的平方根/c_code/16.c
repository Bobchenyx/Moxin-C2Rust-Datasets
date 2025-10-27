int mySqrt(int x){
    int ret=0;
    if(x==1)
    {
        return 1;
    }
    int a=0,b=x,m=0;
    while(1)
    {
        m=(a+b)/2;
        if((long long)m*m<=x)
        {
            if((long long)(m+1)*(m+1)>x)
            {
                ret=m;
                break;
            }
            a=m;
        }
        else
        {
            b=m;
        }
    }
    return ret;
}