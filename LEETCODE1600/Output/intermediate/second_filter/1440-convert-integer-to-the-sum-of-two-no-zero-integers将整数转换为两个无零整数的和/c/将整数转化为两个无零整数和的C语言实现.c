/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool judgeZero(int n)
{
    while(n)
    {
        if(n%10 == 0)
        {
            return false;
        }
        n = n/10;
    }
    return true;
}

int* getNoZeroIntegers(int n, int* returnSize)
{
    //入参检查
    if(n == 0)
    {
        return NULL;
    }

    //分配并初始化数组
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int)*2);

    //循环判断从1~n-1，并返回第一组符合要求的数据
    for(int i = 1; i < n;i++)
    {
        if(judgeZero(i) && judgeZero(n-i))
        {
            result[0] = i;
            result[1] = n-i;
        }
    }
    return result;
}