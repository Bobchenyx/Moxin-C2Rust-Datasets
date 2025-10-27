int removeElement(int* nums, int numsSize, int val) {
	int i = 0;
	if (numsSize == 1 && val == nums[0])
		return 0;
	while (i < numsSize)
	{
		if (nums[i] == val)
		{
			while (nums[numsSize - 1] == val&&numsSize-1 > i)
			{
				numsSize--;
			}
			nums[i] = nums[numsSize - 1];
			numsSize--;
		}
		i++;
	}
	return numsSize;
}