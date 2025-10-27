int* maxDepthAfterSplit(char * seq, int* returnSize){
	int len = strlen(seq);
	int *res = (int*)malloc(sizeof(int)*(len+1));
	int cA = 0;
	int cB = 0;
	for(int i=0;i<len;i++)
	{
		if(seq[i]=='(')
		{
			if(cA<=cB)
			{
				res[i] = 0;
				cA++;
			}
			else
			{
				res[i] = 1;
				cB++;
			}	
		}
		else
		{
			if(cA>=cB)
			{
				res[i] = 0;
				cA--;
			}
			else
			{
				res[i] = 1;
				cB--;
			}
		}
		
	}
	*returnSize = len;
	return res;
}