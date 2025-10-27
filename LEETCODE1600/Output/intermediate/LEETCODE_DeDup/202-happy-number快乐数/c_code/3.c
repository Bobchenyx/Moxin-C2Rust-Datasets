int find_next(int n)
{
    int ans = 0;

    while(n)
    {
        ans += (n % 10) * (n % 10);
        n = n / 10;
    }

    return ans;
}


bool isHappy(int n){
    int fast = find_next(n);
    int slow = n;

    while(fast != slow)
    {
        fast = find_next(fast);
        fast = find_next(fast);
        slow = find_next(slow);
    }

    if(fast == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}