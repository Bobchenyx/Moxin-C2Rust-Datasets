char* longestPalindrome(char* s) {
	if (!(*s) || strlen(s) == 1)//字符串为空或字符串的长度为1直接返回原串
		return s;
	int maxleft, maxright,curleft,curright, i;
	char* out;
	maxleft = maxright = curleft = curright = 0;
	for (i = 1; s[i]; i++)
	{
		curleft = curright = i;
		while (curleft - 1 >= 0 && s[curleft - 1] == s[curleft])
		{
			curleft--;
		}
		while (s[curright + 1] && s[curright + 1] == s[curright])
		{
			curright++;
		}
		curleft--;
		curright++;
		while (curleft >= 0 && s[curright] && s[curleft] == s[curright])
		{
			curleft--;
			curright++;
		}
		curleft++;
		curright--;
		if ((curright - curleft) > (maxright - maxleft))
		{
			maxleft = curleft;
			maxright = curright;
		}
	}
	out = (char*)malloc(sizeof(char) * (maxright - maxleft + 2));
	for (i = maxleft; i <= maxright; i++)
		out[i - maxleft] = s[i];
	out[maxright - maxleft + 1] = '\0';
	return out;
}