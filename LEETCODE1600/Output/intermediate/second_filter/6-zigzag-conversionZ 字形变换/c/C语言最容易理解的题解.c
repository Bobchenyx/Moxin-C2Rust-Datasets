char * convert(char * s, int numRows){
    if(numRows <= 1){
        return s;
    }
    int nLen = strlen(s);
    int *ntemp = (int *)malloc(sizeof(int)*(nLen));
    char *newstr = (char *)malloc(sizeof(char) *(nLen+1));
    int i = 0, j = 0, x = 0;
    int naddflag = 0;
    int nsubflag = 0;
    while(s[i] != '\0'){
    	if(x == numRows -1)
    	{
    		naddflag = 0;
    		nsubflag = 1;
    	}
    	else if(x == 0)
    	{
    		nsubflag = 0;
    		naddflag = 1;
    	}
    	ntemp[i] = x;
    	if(naddflag == 1)
    	{
    		x++;
    	}
    	else
    	{
    		x--;
    	}
    	i++;
    }
    i = 0;
    x = 0;
    for(; i < numRows; i++)
    {
    	for(int j = 0; j< nLen; j++)
    	{
    		if(ntemp[j] == i)
    		{
    			newstr[x] = s[j];
    			x ++;
    		}
    	}
    }
    newstr[nLen] = '\0';
    free(ntemp);
    return newstr;
}