int trap(int* height, int heightSize){
	
	if(heightSize < 3)
	{
		return 0;
	}
	
	int left = height[0], right = height[heightSize - 1];
	int i = 1, j = heightSize - 2;
	int ret = 0;
	
	while(i <= j)
	{
		if(left < right)
		{
			if(height[i] < left)
			{
				ret += left - height[i];
			}
			else
			{
				left = height[i];
			}
			i++;	
		}
		else
		{
			if(height[j] < right)
			{
				ret += right - height[j];
			}
			else
			{
				right = height[j];
			}
			j--;
		}
	}
	return ret;
}