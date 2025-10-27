#define MAX(X,Y) (X > Y ? X : Y)
bool PredictTheWinner(int* nums, int numsSize){
	
	int dp[numsSize][numsSize];
	
	for(int i = 0; i < numsSize; i++)
	{
		dp[i][i] = nums[i];
	}
	
	for(int d = 1; d <= numsSize - 1; d++)
	{
		for(int i = 0; i + d < numsSize; i++)
		{
			dp[i][i + d] = MAX(-dp[i + 1][i + d] + nums[i], -dp[i][i + d - 1] + nums[i + d]);
		}
	}
	
	return dp[0][numsSize - 1] >= 0;
}