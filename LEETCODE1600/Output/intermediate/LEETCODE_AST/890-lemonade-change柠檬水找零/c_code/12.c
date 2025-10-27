bool lemonadeChange(int* bills, int billsSize){
    int i,a=0,b=0;
    if(bills[0]!=5)
    return false;
    a++;
    for(i=1;i<billsSize;i++)
    {
        if(bills[i]==5)
        a++;
        if(bills[i]==10)
        {
            if(a>=1)
            {
                a--;
                b++;
            }
            else
            return false;
        }
        if(bills[i]==20)
        {
            if(a>=1&&b>=1)
            {
                b--;
                a--;
                continue;
            }
            if(a>=3)
            a-=3;
            else
            return false;
        }
    }
    return true;
}