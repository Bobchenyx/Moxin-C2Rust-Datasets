int maxArea(int* height, int heightSize){
    int i = 0, j = heightSize - 1, max = 0, area = 0, width = 0;
    while (i < j){
        width = j - i;
        if (height[i] <= height[j]){
            area = height[i++] * width;
        }else {
            area = height[j--] * width;
        }
        max = (area > max ? area : max);
    }
    return max;
}