bool isPalindrome(int x) {
	double num = 0;
	int cu_x = x;
	if (x == 0)
    {
		return true;
    }
    if((x % 10) == 0 || x < 0) 
    {
        return false;
    }
	while (x > 0)
	{
		num = (num*10) + (x % 10);
		x = x / 10;
	}
	if (num == cu_x)
	{
		return true;
	}
	else
	{
		return false;
	}
}