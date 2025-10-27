char * toLowerCase(char * str){
	
	if((*str) == '\0')
	{
		return str;
	}
	
	if((*str) >= 'A' && (*str) <= 'Z')
	{
		(*str) = (*str) + 'a' - 'A';
	}
	
	toLowerCase(str + 1);
	
	return str;
}