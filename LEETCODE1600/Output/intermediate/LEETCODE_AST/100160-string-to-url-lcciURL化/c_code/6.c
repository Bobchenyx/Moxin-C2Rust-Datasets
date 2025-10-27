char* replaceSpaces(char* S, int length){
	int cntOfSpace = 0;
	for (int i = 0; i < length; i++)
	{
		if (S[i] == ' ')cntOfSpace++;
	}
	//printf("%d", cntOfSpace);
	int j = length + 2 * cntOfSpace;
	S[j] = '\0';
	for (int i = length; i > 0;)
	{
		if (S[--i] == ' ')
		{
			S[--j] = '0';
			S[--j] = '2';
			S[--j] = '%';
		}
		else
		{
			S[--j] = S[i];
		}
	}
	return S;  
}