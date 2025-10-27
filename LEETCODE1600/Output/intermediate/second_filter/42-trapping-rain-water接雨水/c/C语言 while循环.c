int trap(int* height, int heightSize){
    if(heightSize==0 || heightSize==1 || heightSize==2)
        return 0;
    int maxl=0, maxr = 0;
	int i;
	int count = 0;
	//找到最大值的下标
	for (i = 1; i<heightSize; i++)
	{
		if (height[i]>height[maxl])
			maxl = i;
	}
	maxr = maxl;
	//0-max
	while (maxl != 0)
	{
		int max_left = maxl - 1;
		//找到最大值左边的靠近最大值的第二大的值
		for (i = maxl - 1; i >= 0; i--)
		{
			if (height[i]>height[max_left])
				max_left = i;
		}
		//计算两个最大值间雨水的体积
		for (i = max_left + 1; i<maxl; i++)
		{
			count += height[max_left] - height[i];
		}
		maxl = max_left;
	}
	//max-heightSize
	while (maxr != heightSize - 1)
	{
		int max_right = maxr + 1;
		for (i = max_right+1; i < heightSize; i++)
		{
			if (height[i]>height[max_right])
				max_right = i;
		}
		for (i = maxr+1; i<max_right; i++)
		{
			count += height[max_right] - height[i];
		}
		maxr = max_right;
	}
    return count;
}