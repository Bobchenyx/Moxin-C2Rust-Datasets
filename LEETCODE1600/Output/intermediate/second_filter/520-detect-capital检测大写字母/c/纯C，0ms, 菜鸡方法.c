bool detectCapitalUse(char * word){
int len = 0;
	for (len; word[len] != '\0'; len++)
		;
	//len是字符的个数
	if (len == 1)
		return 1;
	int first, second;
	if (word[0] <= 'Z' && word[0] >= 'A')
		first = 1;
	else
		first = 0;
	if (word[1] <= 'Z' && word[1] >= 'A')
		second = 1;
	else
		second = 0;

	if (first == 1 && second == 1)
	{
		for (int i = 2; i < len; i++)
		{
			if (word[i] <= 'Z' && word[i] >= 'A')
				;
			else
				return 0;
		}
		return 1;
	}

	else if (first == 1 && second == 0)
	{
		for (int i = 2; i < len; i++)
		{
			if (word[i] <= 'Z' && word[i] >= 'A')
				return 0;
			else
				;
		}
		return 1;
	}

	else if (first == 0 && second == 0)
	{
		for (int i = 2; i < len; i++)
		{
			if (word[i] <= 'Z' && word[i] >= 'A')
				return 0;
			else
				;
		}
		return 1;
	}
	else if (first == 0 && second == 1)
		return 0;
	else
		return 0;
}