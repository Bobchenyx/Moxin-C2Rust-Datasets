static int stack(int *heights, int n, int *pos, int last)
{
    int max = 0;
    int curr;
    while (*pos < n) {
        if (last >= 0 && heights[last] >= heights[*pos]) {
            return max;
        }

        curr = *pos; // curr是栈中记录的数据，更新curr即是压站
        *pos += 1;
        // 要用上一层记录的index计算面积，需要将上一层的index传入这一层
        // 这一层的index传入下一层，如果是单调栈则可以先弹栈再读取栈顶
        // 如果递归也用这种方法，需要将当前层的height作为返回值弹栈时带出去
        int area = stack(heights, n, pos, curr); 
        max = (max > area) ? max : area;
        area = heights[curr] * (*pos - 1 - last);
        max = (max > area) ? max : area;
    }
    return max;
}

int largestRectangleArea(int *heights, int n)
{
    int pos = 0;
    return stack(heights, n, &pos, -1);
}