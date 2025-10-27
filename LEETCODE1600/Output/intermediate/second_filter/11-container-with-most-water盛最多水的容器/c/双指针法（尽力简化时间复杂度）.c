int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int pivot = 0;
    int maxV = 0;
    int V = 0;

    while (right > left) {
        pivot = (height[left] > height[right])? height[right]: height[left];
        V = pivot * (right - left);
        maxV = V > maxV? V: maxV;
        if (height[left] > height[right])
            while (height[--right] < pivot);
        else
            while (height[++left] < pivot);
    }

    return maxV;
}