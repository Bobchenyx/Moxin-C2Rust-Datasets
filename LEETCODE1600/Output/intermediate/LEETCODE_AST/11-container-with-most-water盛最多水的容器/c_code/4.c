int maxArea(int* height, int heightSize){
int i = 0, j = heightSize - 1;
	int temp = 0;
	double max_area = 0;
	while (j > i)
	{
		temp = height[i] > height[j] ? height[j] : height[i];
        /*
		if (height[i] > height[j])
		{
			temp = height[j];
		}
		else
		{
			temp = height[i];
		}
        */
		if (max_area < (temp * (j - i)))
		{
			max_area = temp * (j - i);
		}
		if (height[j] > height[i])
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return max_area;
}