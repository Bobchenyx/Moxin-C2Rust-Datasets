char * convert(char * s, int numRows){
    int m=strlen(s);
	char *p=(char*)malloc((m+1)*sizeof(char));
	int k=0,i=0;
	int n=2*numRows-2;
	for(;i<numRows;i++)
	{
		int j=i;
		int pr=n-2*i;
		while(j<m)
		{
			p[k]=s[j];
			k++;
			if(i==0 || i==numRows-1)
			{
				if(numRows==1)
                {
                    j=j+1;
                } 
                else
                {
                    j=j+n;
                }
			}
			else
			{
				j=j+pr;
				pr=n-pr;	
			} 
		}
	}
	p[m]='\0';
	return p;
}