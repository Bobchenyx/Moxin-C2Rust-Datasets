int longestPalindrome(char* s)
{
	int hash[52] = { 0 };
	int tem[1000] = { 0 };  //用来记录奇数最大数值
	int cnt = 0;
	int i, j = -1;

	for (i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			hash[s[i] - 97]++;
		}
		else
		{
			hash[s[i] - 39]++;
		}
	}

	for (i = 0; i < 52; i++)
	{
		if (hash[i] % 2 == 0)
		{
			cnt += hash[i];
		}
		else if (hash[i] % 2 != 0) // 记录非偶数
		{
			tem[++j] = hash[i];
		}
	}

	int max;
	int symbol; //记录最长计数串的下标
	max = tem[0];  //最长的奇数串
	symbol = 0;
	for (i = 1; i < j+1; i++)
	{
		if (tem[i] > max)
		{
			max = tem[i];
			symbol = i;
		}
	}

	//printf("%d", symbol);
	for (i = 0; i < j + 1; i++)
	{
		if (i != symbol)
		{
			cnt = cnt + tem[i] - 1;
		}
	}
	return cnt + max;
}