int longestValidParentheses(char * s){
	int count = 0,len = 0,res = 0;
	int LS = strlen(s);
	for(int i=0;i<LS;i++)
	{
		if(s[i]=='(')   count++;
		if(s[i]==')')
		{
			if(count>0)
			{
				count--;
				len +=2;
			}  
			else
			{
				res = res>len?res:len;
				count = 0;
				len = 0;
			}
		} 
	}
	if(count!=0)
	{
		int low = LS-count-len;
		count = 0;
		len = 0;
		for(int i=LS-1;i>=low;i--)
		{
			if(s[i]==')')  count++;
		    if(s[i]=='(')
		    {
		    	if(count>0)
		    	{
		    		count--;
		    		len+=2;
		    	}
		    	else
		    	{
		    		res = res>len?res:len;
					count = 0;
					len = 0;	
		    	}
		    }
		}
	}
	res = res>len?res:len;
	return res;
}