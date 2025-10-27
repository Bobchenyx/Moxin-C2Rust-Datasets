bool isPalindrome(int x) {
    if(x<0)
        return 0;
	int a[1000];
	int i = 0;
	int left, right;
	while (x != 0)
	{
		a[i++] = x % 10;
		x /= 10;
	}
	left = 0;
	right = i - 1;
	while (left < right)
	{
		if (a[left] != a[right])
		{
			return 0;
		}
		left++;
		right--;
	}
	return 1;
}