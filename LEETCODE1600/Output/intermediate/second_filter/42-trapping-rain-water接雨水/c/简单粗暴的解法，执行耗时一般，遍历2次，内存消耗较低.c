int FindMax(int* height, int size, int* maxIdx)
{
    int max, i;
    max = height[0];
    *maxIdx = 0;
    for (i = 1; i < size; i++) {
        if (height[i] > max) {
            max = height[i];
            *maxIdx = i;
        }
    }
    return max;
}

int CalcSumLeft(int* height, int leftIdx, int leftLen)
{
    int i, last, sum;
    last = height[leftIdx];
    sum = 0;
    for (i = leftIdx + 1; i < leftIdx + leftLen; i++) {
        if (height[i] < last) {
            sum += last - height[i];
        } else {
            last = height[i];
        }
    }
    return sum;
}

int CalcSumRight(int* height, int rightIdx, int rightLen)
{
    int i, last, sum, startIdx;
    startIdx = rightIdx + rightLen - 1;
    last = height[startIdx];
    sum = 0;
    for (i = startIdx - 1; i >= rightIdx; i--) {
        if (height[i] < last) {
            sum += last - height[i];
        } else {
            last = height[i];
        }
    }
    return sum;
}

int trap(int* height, int heightSize){
    int max, maxIdx, sum;
    int leftLen, rightLen, leftIdx, rightIdx;
    if (height == NULL || heightSize < 3) {
        return 0;
    }
    max = FindMax(height, heightSize, &maxIdx);
    leftLen = maxIdx + 1;
    rightLen = heightSize - maxIdx;
    sum = 0;
    if (leftLen > 0) {
        leftIdx = 0;
        sum += CalcSumLeft(height, leftIdx, leftLen);
    }
    if (rightLen > 0) {
        rightIdx = maxIdx;
        sum += CalcSumRight(height, rightIdx, rightLen);
    }
    return sum;
}