int trap(int* height, int heightSize){//动态规划
    int num = 0;
    int temp = 0;
    int* max_left = (int*)malloc(heightSize*sizeof(int));
    int* max_right = (int*)malloc(heightSize*sizeof(int));
    for (int i = 1; i < heightSize - 1; i++)
    {
        if (max_left[i - 1] < height[i - 1])
            max_left[i] = height[i - 1];
        else
            max_left[i] = max_left[i - 1];

    }
    for (int i = heightSize - 2; i >= 0; i--)
    {
        if (max_right[i + 1] < height[i + 1])
            max_right[i] = height[i + 1];
        else
            max_right[i] = max_right[i + 1]; 
    }
    for (int i = 1; i < heightSize - 1; i++)
    {

        if (max_left[i] <= max_right[i])
            temp = max_left[i];
        else 
            temp = max_right[i];

        if (height[i] < temp)
            num += temp - height[i];
        else
            continue;
    }
    return num;
}