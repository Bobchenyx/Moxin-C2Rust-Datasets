bool isPalindrome(int x)
{
    long int y = 0;
    int t = x;
    if((x < 0) || ((x != 0) && (x % 10) == 0))
    {
        return false;
    }
    else
    {
        do
        {
            y = y * 10 + t % 10;
            t = t / 10;
        }while(t > 0);
        return (y == x) ? true : false;
    }

}