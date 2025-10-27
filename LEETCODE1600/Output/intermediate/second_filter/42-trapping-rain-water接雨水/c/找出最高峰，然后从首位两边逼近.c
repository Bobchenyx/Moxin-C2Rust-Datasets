int trap(int* height, int heightSize){
int min(int a, int b);
	int max(int a, int b);
	int i, j, k, min_value, drop, max_pos, max_value;;
	min_value = 0; drop = 0;//雨滴数
	max_pos = 0;//初始化
	max_value = 0;
	for (i = 0; i < heightSize; i++)
	{
		if(height[i] > max_value) 
         {
             max_value = height[i]; 
         max_pos = i;
         }
		
	}
	if (max_pos != 0)
	{
		for (i = 0; i <= max_pos - 1; i++)
		{
			if (!height[i]) { continue; }
			for (j = i + 1; j <= max_pos; j++)
			{
				if (height[i] <= height[j])

				{
					min_value = min(height[i], height[j]);
					drop = drop + min_value * abs(j - i - 1);
					printf("I:%d, j:%d, drop:%d\n", i, j, drop);
					for (k = i + 1; k < j; k++)
					{
						drop = drop - height[k];
						printf("drop: %d,height[%d]:%d\n", drop, k, height[k]);
					}
					i = j - 1;
					break;
				}
			}
		}
	}
	for (i =heightSize-1; i >= max_pos+1; i--)
	{
		if (!height[i]) { continue; }
		for (j = i-1; j >= max_pos; j--)
		{
			if (height[i] <= height[j])

			{
				min_value = min(height[i], height[j]);
				drop = drop + min_value * abs(i-j - 1);
				printf("i:%d, j:%d, drop:%d\n", i, j, drop);
				for (k = i - 1; k > j; k--)
				{
					drop = drop - height[k];
					printf("drop: %d,height[%d]:%d\n", drop, k, height[k]);
				}
				i = j + 1;
				break;
			}
		}
	}
	printf("drop: %d\n", drop);
    return drop;
}
int min(int a, int b)
{
	return a <= b ? a : b;
}