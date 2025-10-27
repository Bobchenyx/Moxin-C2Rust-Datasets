#define MAX 50000
struct stackInfo {
    int rightId[MAX]; //记录Node右边第一个高度小于的索引
    int leftId[MAX];  //记录Node左边第一个高度小于的索引
    int top;
};

struct stackInfo g_stackInfo;

int GetMax(int pos, int max, int *heights, int *idx, int curHeight)
{
    int temp;

    while (g_stackInfo.top > 0 && heights[g_stackInfo.rightId[g_stackInfo.top]] > curHeight) {//保持栈为递增
        temp = heights[g_stackInfo.rightId[g_stackInfo.top]] * (pos - g_stackInfo.leftId[g_stackInfo.top]);
        if (max < temp) {
            max = temp;
        }
        *idx = g_stackInfo.leftId[g_stackInfo.top];  //出队数比当前数大，可以组成矩形，索引更新到出队的索引
        g_stackInfo.top--;
    }

    return max;
}

int largestRectangleArea(int* heights, int heightsSize){
    int idx;
    int max = 0;

    if (heightsSize <= 0) {
        return 0;
    }
    memset(&g_stackInfo, 0, sizeof(struct stackInfo));
    for (int i = 0; i < heightsSize; i++) 
    {
        idx = i;
        max = GetMax(i, max, heights, &idx, heights[i]); //按顺序获取每次最大的矩形
        g_stackInfo.rightId[++g_stackInfo.top] = i; //索引入栈
        g_stackInfo.leftId[g_stackInfo.top] = idx; //记录索引

        if (i == heightsSize - 1) {  //最后加入0，清空栈
            max = GetMax(heightsSize, max, heights, &idx, 0);
        }
    }

    return max;
}