void rotate(int* nums, int numsSize, int k){
	int i = 0, j = 0;
	k = k % numsSize;
	for (i = 0, j = numsSize - 1 - k; i<j; i++, j--){
		nums[i] = nums[i] ^ nums[j];
		nums[j] = nums[i] ^ nums[j];
		nums[i] = nums[i] ^ nums[j];
	}
	for (i = numsSize - k, j = numsSize - 1; i<j; i++, j--){
		nums[i] = nums[i] ^ nums[j];
		nums[j] = nums[i] ^ nums[j];
		nums[i] = nums[i] ^ nums[j];
	}
	for (i = 0, j = numsSize-1; i<j; i++, j--){
		nums[i] = nums[i] ^ nums[j];
		nums[j] = nums[i] ^ nums[j];
		nums[i] = nums[i] ^ nums[j];
	}
}