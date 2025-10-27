C []
int maxArea(int* height, int heightSize){
    if (height == NULL || heightSize < 2) {
        return 0;
    }

    int result = 0;
    int i = 0; 
    int j = heightSize - 1;

    while (i < j) {
        int h = MIN(height[i], height[j]);
        result = MAX(result, h * (j - i ));

        if (height[i] < height[j]) {
            i++;
        }
        else {
            j--;
        }
    }

    return result;
}