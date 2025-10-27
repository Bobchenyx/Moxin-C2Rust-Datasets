int searchInsert(int* nums, int numsSize, int target)
{
	if (numsSize == 1)
	{
		if (nums[0] >= target)
		{
			return 0;
		}
		return 1;
	}

	int left = 0;
	int right = numsSize - 1;
	if (nums[left] > target)
	{
		return 0;
	}
	if (nums[right] < target)
	{
		return numsSize;
	}

	while (right - left > 1)
	{
		if (nums[left] == target)
		{
			return left;
		}
		if (nums[right] == target)
		{
			return right;
		}
        
		int temp = (right + left + 1) / 2;
		
		if (nums[temp] == target)
		{
			return temp;
		}
		if (nums[temp] > target)
		{
			right = temp;
		}
		else
		{
			left = temp;
		}
	}

	if (right == left)
	{
		if (nums[left] >= target)
		{
			return left;
		}
		else
		{
			return right + 1;
		}
	}
	else
	{
		if (nums[left] == target)
		{
			return left;
		}
		if (nums[right] >= target)
		{
			return right;
		}
	}
	return 0;  // 不加默认出口会报错，可能是因为其他的出口都需要判断的原因
}