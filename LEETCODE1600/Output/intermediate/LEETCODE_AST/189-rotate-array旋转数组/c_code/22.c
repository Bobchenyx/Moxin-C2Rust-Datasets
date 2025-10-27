void rotate(int* nums, int numsSize, int k) {
	k = k % numsSize;
	int* nums1 = (int*)malloc(4 * numsSize * 2);
	assert(nums1);
	int i = 0;
	while (i < numsSize)
	{
		nums1[i] = nums[i];
		i++;
	}
	i = 0;
	while (i < numsSize)
	{
		nums1[i+ numsSize] = nums[i];
		i++;
	}
	int j = 0;
	i = numsSize - k;
	while (j < numsSize)
	{
		nums[j] = nums1[i];
		i++;
		j++;
	}
	free(nums1);
}