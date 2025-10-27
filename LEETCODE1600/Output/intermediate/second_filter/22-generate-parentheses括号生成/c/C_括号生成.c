void dfs(char* stack, int top, int n, int leftNum, int rightNum, char** result, int* returnSize)
{
	if (leftNum == n && rightNum == n)
	{
		result[*returnSize] = (char*)malloc(sizeof(char)*n * 2 + 1);
		for (int i = 0; i < n * 2; ++i)
			result[*returnSize][i] = stack[i];
		result[*returnSize][n * 2] = '\0';
		++(*returnSize);
		return;
	}
	if (leftNum < n)
	{
		stack[top] = '(';
		dfs(stack, top+1, n, leftNum + 1, rightNum, result, returnSize);
	}
	if (leftNum > rightNum)
	{
		stack[top] = ')';
		dfs(stack, top+1, n, leftNum, rightNum + 1, result, returnSize);
	}
}
char ** generateParenthesis(int n, int* returnSize) {
	char* stack = (char*)malloc(sizeof(char) * 2 * n+1);
	char** result = (char**)malloc(sizeof(char*) * 2048);
	*returnSize = 0;
	dfs(stack, 0, n, 0, 0, result, returnSize);
	return result;
}