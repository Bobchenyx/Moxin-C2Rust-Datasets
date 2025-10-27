char * longestCommonPrefix(char ** strs, int strsSize){
	if(!strsSize)return "";
	int i;
	int j = 0;
	int k = 0;
    char *a;
	while(1)
	{
		if(strs[0][j] == '\0') break;
		for(i=1;i<strsSize;i++)
		{
			if(strs[i][j] == '\0'||strs[0][j]!=strs[i][j])break;
		}
        if(i!=strsSize)break;
        k++;
        j++;
	}
    a = (char*)malloc(sizeof(char)*(k+1));
    a[k] = '\0';
    for(j=0;j<k;j++)
    {
        a[j] = strs[0][j];
    }
	return a;
}