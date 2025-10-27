int g_stack[50000] = {0};
int g_stackLen;

int largestRectangleArea(int* heights, int heightsSize)
{
    int maxArea = 0;
    int tmpArea;
    int h;
    int l;
    int loop;

    // 初始化
    g_stack[0] = -1;
    g_stackLen = 1;

    for (loop = 0; loop < heightsSize; loop++) {
        /* 1. 每找到一个非递增的高度则计算面积并出栈 */
        while ((g_stack[g_stackLen - 1] >= 0) && (heights[loop] < heights[g_stack[g_stackLen - 1]])) {
            l = loop - 1 - g_stack[g_stackLen - 2];     // 由于为单调递增, 故长度为该点到当前非递增点
            h = heights[g_stack[g_stackLen - 1]];       // 高度即为该点高度
            tmpArea = l * h;
            maxArea = (maxArea > tmpArea) ? maxArea : tmpArea;
            g_stackLen--;
        }
        /* 2. 新参数入栈 */
        g_stack[g_stackLen++] = loop;
    }

    // 3. 结束时可认为单调递减, 再执行一次运算
    while (g_stack[g_stackLen - 1] >= 0) {
        l = loop - 1 - g_stack[g_stackLen - 2];     // 由于为单调递增, 故长度为该点到当前非递增点
        h = heights[g_stack[g_stackLen - 1]];       // 高度即为该点高度
        tmpArea = l * h;
        maxArea = (maxArea > tmpArea) ? maxArea : tmpArea;
        g_stackLen--;
    }

    return maxArea;
}