bool isPalindrome(int x)
{
    int arr[120] = {0};
    int i = 0, p = 0;
    if(x < 0)           //x为负数时，不是回文数，直接返回false
    {
        return false;
    }
    else
    {
        while(0 != x)
        {
            arr[i++] = x % 10;  //通过取余，将x的最后一位数字取出
            x/=10;              //将最后一位数字去掉，方便取余
        };
        i--;
        for(p = 0; p <= i; p++)
        {
            if(arr[p] != arr[i--])
            {
                return false;
            }
        }
        return true;
    }
}