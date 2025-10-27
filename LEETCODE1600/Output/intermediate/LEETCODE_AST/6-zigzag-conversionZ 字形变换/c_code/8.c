char * convert(char * s, int numRows)
{
	char arr[numRows][1000];
	int i=0,j=0,k=0;
	char *a;
	a=(char *)malloc(sizeof(char)*(strlen(s)+1));
	memset(a,0,strlen(s)+1);
    for(k=0;k<numRows;k++)
    {
        memset(arr[k],0,1000);
    }
    if(numRows==1) return s;
	RE: for(i;s[i]!=0;i++)
	{
		strncat(arr[j],&s[i],1);
		j++;
		if(j==numRows)//表示最后一排已经赋值
		{
			j-=2;
			i++;
			break; 
		} 
		
	}
	for(i;s[i]!=0;i++)
	{
		strncat(arr[j],&s[i],1);
		j--;
		if(j==-1)
		{
			j+=2;
			i++;
			goto RE;
		}
		
	}
	for(i=0;i<numRows;i++)
	{
		strcat(a,arr[i]);
	}
	return a;
}