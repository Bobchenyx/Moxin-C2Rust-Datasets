bool isValid(char* s) {
	if (!(*s))//空字符串返回真
		return 1;
	if (s[0] == ')' || s[0] == ']' || s[0] == '}')//开头出现右括号的直接输出false
		return 0;
	int len = strlen(s);
	if (len % 2 != 0)//括号肯定不能全部配对
		return 0;

	char* stack = (char*)malloc(sizeof(char) * (len));
	int i, index;//index为堆栈指针
	char c;
	i = 0;
	index = -1;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			index++;
			stack[index] = s[i];

		}
		else
		{
			c = stack[index];
			index--;
			if (!(c == '(' && s[i] == ')' || c == '[' && s[i] == ']' ||
				c == '{' && s[i] == '}'))
				return 0;
		}
		i++;
	}
	if (index >= 0)
		return 0;
	return 1;
}