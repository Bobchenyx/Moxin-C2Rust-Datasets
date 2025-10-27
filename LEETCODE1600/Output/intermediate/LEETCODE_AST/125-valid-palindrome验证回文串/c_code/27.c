bool isPalindrome(char * s) {
	//输入为空的时候
	if (s==0||*s == '\0')
		return true;
	//头指针和尾指针
	char* low = s;
	char* high = s;
	while (*high != '\0')
	{	
		//尾指针定位到末尾的过程中，把字母统一成小写
		if ('A' <= *high&&*high <= 'Z')
			*high += ('a' - 'A');
		++high;
	}
	//相向迭代如果二者都是 字母或者数字 比较
	while (low <= high) 
	{
		if (!(('a' <= *low&&*low <= 'z') || ('0' <= *low&&*low <= '9')))
		{
			++low;
			continue;
		}
		if (!(('a' <= *high&&*high <= 'z') || ('0' <= *high&&*high <= '9')))
		{
			--high;
			continue;
		}
		if (*low != *high)
			return false;
		++low; -- high;
	}
	return true;
}