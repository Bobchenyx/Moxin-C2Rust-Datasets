int lengthOfLastWord(char * s){

 int WordLength = 0;
int WordLengthCount = 0;
	
	while(*s != '\0')
	{
		while(*s != ' ')
		{
			while((*s != ' ') && (*s != '\0'))
			{
				WordLengthCount++;
				WordLength = WordLengthCount;
				s++;
			}
			if(*s == '\0')
				return WordLength;
			s++;
			WordLengthCount = 0;
		}
		if(*s == '\0')
			return WordLength;
		s++;
	}
	return WordLength;
}