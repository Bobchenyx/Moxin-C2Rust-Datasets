int trap(int* height, int heightSize){
    int num = 0;
    for (int i = 1; i < heightSize - 1; i++)
    {
        int max_left = 0;
        int temp = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (height[j] > max_left)
                max_left = height[j];
        }
        int max_right = 0;
        for (int k = i + 1; k < heightSize; k++)
        {
            if (height[k] > max_right)
                max_right = height[k];
        }
        if (max_left <= max_right)
            temp = max_left;
        else 
            temp = max_right;

        if (height[i] < temp)
            num += temp - height[i];
        else
            continue;
    }
    return num;
}