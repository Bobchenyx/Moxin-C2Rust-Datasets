/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backTrack(char **res,char str[],int id,int n,int l,int r,int *returnSize){
	//PrintS(str,id);
	if(l==n&&r==n)
	{
		str[id] = '\0';
		res[*returnSize] = (char*)malloc(sizeof(char)*(id+1));
		strcpy(res[*returnSize],str);
		//Print(res,returnSize);
		(*returnSize)++;
		return;
	}
	if(l<n)
	{
		str[id] = '(';
	    backTrack(res,str,id+1,n,l+1,r,returnSize);
	}
	if(r<l)
	{
		str[id] = ')';
		backTrack(res,str,id+1,n,l,r+1,returnSize);
	}
	
}
char ** generateParenthesis(int n, int* returnSize){
	char **res = (char**)malloc(sizeof(char*)*1000000);
	char str[n*2+1];
	*returnSize = 0;
	backTrack(res,str,0,n,0,0,returnSize);
	return res;
}