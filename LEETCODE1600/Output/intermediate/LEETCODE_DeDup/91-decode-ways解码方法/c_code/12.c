int numDecodings(char* s) {
	if (strlen(s) <= 1)
	{
		if (s[0] == '0')
			return 0;
		else return strlen(s);
	}
	else
	{
		int len = strlen(s);
		int sum[5000] = { 0 };
		
		if (s[0] == '0')//0和1列出来单独讨论
			return 0;
		else sum[0] = 1;

		if (s[1] == '0')
			if (s[0] <= '2' && s[0] > '0')
				sum[1] = sum[0];
			else return 0;
		else if ('0' < s[0] && s[0] < '2')
			sum[1] = sum[0] + 1;
		else if (s[1] <= '6' && s[0] == '2')
			sum[1] = sum[0] + 1;
		else sum[1] = sum[0];

		for (int i = 2; i < len; i++)
		{
			if (s[i] == '0')
				if (s[i - 1] <= '2' && s[i - 1] > '0')
					sum[i] = sum[i - 2];
				else return 0;
			else if ('0'<s[i-1] &&s[i-1]<'2')
				sum[i] = sum[i-1] + sum[i-2];
			else if (s[i] <= '6'&& s[i - 1] == '2')
				sum[i] = sum[i - 1] + sum[i - 2];
			else sum[i] = sum[i-1];
		}
		return sum[len-1];
	}

}