bool isPalindrome(int x)
{
    int n,tem;
    long int m=0;
    tem=x;
    if(x<0)
    return false;
    while(x>0)
    {
        n=x%10;
        m=m*10+n;
        x/=10;

    }
     if(m==tem)
        return true;
     else
     return false;
}