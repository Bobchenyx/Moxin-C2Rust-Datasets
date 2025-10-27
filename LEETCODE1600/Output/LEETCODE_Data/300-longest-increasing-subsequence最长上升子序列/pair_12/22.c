int lengthOfLIS(int* nums, int numsSize) {
	if (numsSize <= 1) return numsSize;
	int* dp = (int*)malloc(sizeof(int)*numsSize);
	for (int i = 0; i < numsSize; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : (dp[j] + 1);
			}
		}
	}
	int maxLen = dp[0];
	for (int i = 1; i < numsSize; i++) {
		if (maxLen < dp[i]) maxLen = dp[i];
	}
	return maxLen;
}