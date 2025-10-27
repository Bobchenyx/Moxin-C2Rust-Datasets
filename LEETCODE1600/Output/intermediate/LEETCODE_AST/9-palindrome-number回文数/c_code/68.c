int getBits(int n)
{
    int rst = 0;
    while (n)
    {
        rst++;
        n /= 10;
    }
    return rst;
}
bool isPalindrome(int x){
 if (x < 0)
    {
        return false;
    }
    int bits = getBits(x);
    for (int i = 0; i < bits / 2; i++)
    {
        int tmp = (int)pow(10, i + 1);
        int tmp_ = (int)pow(10, i);
        int bit = (x % tmp) / tmp_;

        int j = bits-i-1;
        int tmp2 = (int)pow(10,j+1);
        int tmp2_ = (int)pow(10,j);
        int bit2 = (x%tmp2)/tmp2_;

        if(bit != bit2)
        {
            return false;
        }
    }
    return true;
}