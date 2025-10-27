char* compressString(char* S)
{
	int i, len;
	int cnt = 1;
	int j = -1;
    char dealS[500000];
	memset(dealS, '0', 500000);

	char ch = S[0];
	for (i = 0; S[i]; i++);  //测量长度 其实可以用strlen
	len = i;
	if (len == 1)
	return S;
	for (i = 1; i < len+1; i++)  //len+1是为了防止还没等压缩就因为到了末尾而跳出遍历了了
	{
		if (ch == S[i])
		{
			cnt++;
		}
		else
		{
			dealS[++j] = ch;
			if (cnt < 10) //判断计数器大于还是小于0
			{
				dealS[++j] = (char)(cnt + 48);
			}
			else
			{
				char buffer[25];
				sprintf(buffer, "%d", cnt);
				for (int k = 0; buffer[k]; k++)
				{
					dealS[++j] = buffer[k];
				}
			}

			ch = S[i];
			i--;
			cnt = 0;
		}
	}

	dealS[++j] = '\0';
	return strlen(dealS) < strlen(S) ? dealS : S;
}