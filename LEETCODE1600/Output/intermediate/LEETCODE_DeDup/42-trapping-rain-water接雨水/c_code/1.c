int trap(int* height, int heightSize){
    int sum = 0;
    int tmpSum = 0;
    int lastTop = 0;
    int top = 0;

    int i;
    /* 正向算面积 */
    for (i = 0; i < heightSize; i++) {
        if (height[i] > top) {
            top = height[i];
            sum += tmpSum;
            lastTop = top;
            tmpSum = 0;
        }
        if (height[i] <= top) {
            tmpSum += lastTop - height[i];
            // printf("i %d tmpSum = %d\n",i,tmpSum);
        }
    }
    // printf("sum is %d\n",sum);
    tmpSum = 0;
    lastTop = 0;
    top = 0;
    /* 反向算面积 */
    for (i = heightSize - 1; i >= 0; i--) {
        if (height[i] >= top) {
            top = height[i];
            sum += tmpSum;
            lastTop = top;
            tmpSum = 0;
        }
        if (height[i] < top) {
            tmpSum += lastTop - height[i];
            // printf("i %d tmpSum = %d\n",i,tmpSum);
        }
    }
    return sum;
}