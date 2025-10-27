char* gcdOfStrings(char* str1, char* str2) //str1长  str2短
{
	int i = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int lenFir = len1;
	int lenSec = len2;
	char *maxSubString;
	int gcd, flag = 0;
	int j;

	maxSubString = (char *)malloc(sizeof(char) * 1000);
	memset(maxSubString, 0, 1000);
	gcd = len1 % len2;
	while (gcd != 0)  
	{
		len1 = len2;
		len2 = gcd;
		gcd = len1 % len2;
	}
	if (lenFir > lenSec)
	{
		for (i = 0; i < strlen(str2); i++)
		{
			if (str2[i] != str1[i])
				break;
		}

		if (str1[i] != str2[0])  //比较长字符串的下一个字符是否等于短字符串的第一个字符
		{
			flag = 1;
		}
	}
	else if(lenFir < lenSec)
	{
		for (i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
				break;
		}
		
		if (str1[0] != str2[i])
		{
			flag = 2;
		}
	}
	else if(lenFir = lenSec)
	{
		if (strcmp(str1, str2) == 0)
		{
			flag = 3;
		}
	}

	for (j = 0; j < len2; j++)  //最长字符串 len2是最大公约数
	{
		maxSubString[j] = str2[j];
	}

	if (i==strlen(str2) && flag==0  ||  i==strlen(str1) && flag==0)
	{
		return maxSubString;
    }
	else if (flag == 3)
	{
		return str2;
	}
	else 
	{
		return "";
	}

}