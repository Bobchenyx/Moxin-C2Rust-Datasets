int countCharacters(char ** words, int wordsSize, char * chars)
{
	int ret = 0;
	int len = strlen(chars);
	char table1[26] = {0}; // 用来统计各个字符的个数
	char table2[26] = {0}; // 用来备份table1
	int i = 0, j = 0, k = 0;
	for ( i = 0; i < len; i++) // 统计chars中各个字符的个数
	{
		table1[chars[i]-'a']++;
	}

	for ( i = 0; i < wordsSize; i++) 
	{
		int wordLen = strlen(words[i]);
		if(wordLen > len)  // 如果word的长度>chars的长度，则直接进行下个word的判断
		{
			continue;
		}
		memcpy(table2, table1, 26);
		for ( j = 0; j < wordLen; j++) 
		{
			if(table2[words[i][j]-'a']-- <= 0)
            {
                break;
            }            
		}
		if(j == wordLen)
		{
			ret += wordLen;
		}
	}

	return ret;
}