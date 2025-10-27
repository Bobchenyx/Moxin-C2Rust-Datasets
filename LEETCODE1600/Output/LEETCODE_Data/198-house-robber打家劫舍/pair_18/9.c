int max(int a, int b) {
	 return a>b ? a : b;
}

//动态规划解决
int rob(int* nums, int numsSize){
	int *dp = (int *)malloc((numsSize)*sizeof(int));
	int i;
	if (numsSize > 0){
		dp[0] = nums[0];
	}
	else{
		return 0;
	}

	if (numsSize > 1){
		dp[1] = max(nums[0], nums[1]);
	}

	for (i = 2; i < numsSize; i++){
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp[numsSize - 1];
}