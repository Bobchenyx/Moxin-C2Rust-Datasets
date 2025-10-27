int maxSubArray(int* nums, int numsSize) {
	int maxNum = nums[0];
	int temp = 0;
	if (nums == NULL) {
		return 0;
	}
	if (numsSize == 1) {
		return nums[0];
	}
	for (int i = 0; i < numsSize; i++) {
		temp = nums[i];
		if (maxNum < temp) {
			maxNum = temp;
		}
		for (int j = i + 1; j < numsSize; j++) {
			temp += nums[j];
			if (maxNum < temp) {
				maxNum = temp;
			}
		}
	}
	if (maxNum < temp) {
		maxNum = temp;
	}
	return maxNum;
}