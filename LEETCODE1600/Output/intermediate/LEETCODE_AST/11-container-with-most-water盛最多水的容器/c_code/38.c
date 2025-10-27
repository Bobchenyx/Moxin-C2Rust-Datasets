int maxArea(int* height, int heightSize){
    int max = 0;
    int min = 0;
    int tmp = 0;
    int i = 0;
    int j = heightSize - 1;
    
    while (i < j) {
        min = height[i] < height[j] ? height[i] : height[j];
        tmp = min * (j - i);
        max = tmp > max ? tmp : max;
        while (height[i] <= min && i < j) ++i;
        while (height[j] <= min && i < j) --j;
    }
    
    return max;
}