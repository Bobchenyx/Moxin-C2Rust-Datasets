bool isLongPressedName(char * name, char * typed){

    int len1 = strlen(name);
	int len2 = strlen(typed);

	char word1[1000] = { '\0' };
	int  nums1[1000] = { 0 };
	char word2[1000] = { '\0' };
	int  nums2[1000] = { 0 };

	if (len1>len2)
	{
		return false;
	}

	char p = name[0];
	int j = 0;
	word1[0] = p;
	int i = 0;
	for (; i<len1; i++)
	{
		if (p!=name[i])  //如果不相等
		{
			p = name[i];
			j++;
			nums1[j]++;
			word1[j] = p;

		}
		else
		{
			nums1[j]++;
		}
	}

	 p = typed[0];
	j = 0;
	word2[0] = p;
	i = 0;
	for (; i<len2; i++)
	{
		if (p!=typed[i])  //如果不相等
		{
			p = typed[i];
			j++;
			nums2[j]++;
			word2[j] = p;

		}
		else
		{
			nums2[j]++;
		}
	}


	for (i = 0; i<1000; i++)
	{
		if (word1[i]==word2[i])
		{
			if ('\0' == word1[i])
			{
				if ('\0' == word2[i])
				{
					return true;
				}
				return false;
			}

			if (nums2[i] >= nums1[i])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
        return false;
	}
	return true;

}