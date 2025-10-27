int fib(int n)
{
    int result = 0;
    if(n <= 0)
    {
        result = 0;
    }
    else if(n == 1) 
    {
        result = 1;
    }
    else
    {
        int i=n-1;
        int curr = 0, next = 1;
        while(i--)
        {
            result=(curr+next)%1000000007;
            curr=next;
            next=result;
        }
    }
    return result;    
}