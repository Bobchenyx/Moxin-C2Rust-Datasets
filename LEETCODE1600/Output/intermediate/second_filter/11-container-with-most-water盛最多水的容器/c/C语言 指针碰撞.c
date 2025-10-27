int maxArea(int* height, int heightSize){
    if (height == NULL || heightSize == 0) {
        return 0;
    }

    if (heightSize == 1) {
        return height[0];
    }

    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while(left < right) {
        if (height[left] < height[right]) {
            int newMax = height[left] * (right - left);
            max = max >= newMax ? max : newMax;
            left++;
        }else {
            int newMax = height[right] * (right - left);
            max = max >= newMax ? max : newMax;
            right--;
        }
    }
    return max;
}