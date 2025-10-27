char* longestCommonPrefix(char** strs, int strsSize) {
	if(!strsSize)
        return (char*)"";
    char *pub_str;
	int min_index = 0;
	int min_length = strlen(strs[0]);
	int i;
	int k = 0;
	int sameflag;
	//寻找最小的串长的字符串
	for (i = 0; i < strsSize; i++)
	{
		if (min_length > strlen(strs[i]))
		{
			min_index = i;
			min_length = strlen(strs[i]);
		}
	}
	for (i = 0; strs[min_index][i]; i++)
	{
		sameflag = 1;
		for (int j = 0; j < strsSize; j++)
		{
			if (strs[j][i] != strs[min_index][i])
			{
				sameflag = 0;
				i = min_length - 1;
				break;
			}
		}
		if (sameflag)
			k++;
	}
	if (k)
	{
		pub_str = (char*)malloc(sizeof(char) * (k+1));
		for (i = 0; i < k; i++)
			pub_str[i] = strs[min_index][i];
		pub_str[i] = '\0';
		return pub_str;
	}
	return (char*)"";
}