int myAtoi(char * str){
		int flag = 1;
	double num = 0;
	while ((*str) == ' ')
	{
		str++;
	}
	if (*str == '-') {
		flag = -1;
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		num = (num * 10) + (*str - '0');
		if (num != (int)num) {//溢出判断
			return flag == 1 ? INT_MAX : INT_MIN;
		}
			str++;
	}
	num *= flag;
	return num;
}