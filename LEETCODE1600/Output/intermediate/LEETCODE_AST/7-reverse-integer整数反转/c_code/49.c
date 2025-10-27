int reverse(int x)
{
    int max = 2147483647, min =-2147483648;
    long result=0;
        while(x!=0)
            {
                result=result*10+x%10;
                x=x/10;
            }
    return result>max||result<min?0:result; 
}