int myAtoi(char* str) {
	double out = 0;
	int flagneg,i;
	i = flagneg = 0;
	while(str[i]==' ')
        i++;
    if(str[i]=='-')
    {
        flagneg = 1;
        i++;
    } 
    else if(str[i] == '+')
        i++;
    if(str[i]<'0' || str[i]>'9')
        return 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0';
		if (out < INT_MIN || out > INT_MAX)
			break;
		i++;
	}
	if (flagneg)
	{
		out *= -1;
	}
	if (out > INT_MAX)
		return INT_MAX;
	if (out < INT_MIN)
		return INT_MIN;
	return out;
}