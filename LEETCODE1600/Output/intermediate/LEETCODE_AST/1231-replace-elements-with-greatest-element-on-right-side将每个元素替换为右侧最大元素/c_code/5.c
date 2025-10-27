/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int maxNumber(int *arr, int start, int end)
{
    int max = 0;
    if(!arr)
    {
        max = 0;
    }
    else
    {
        max = arr[start];
        for(int i=start; i<end;i++)
        {
            if(arr[i] >= max)
            {
                max = arr[i];
            }
        }
    }
    return max;
}

int* replaceElements(int* arr, int arrSize, int* returnSize)
{
    //入参检查
    if(!arr)
    {
        *returnSize = 0;
        return NULL;
    }

    //分配并初始化数组
    int *result = (int*)malloc(sizeof(int)*arrSize);
    memset(result, -1, sizeof(int)*arrSize);

    //循环遍历数组，获取最大值
    int max = 0;
    for(int i = 0; i<arrSize-1;i++)
    {
        max = maxNumber(arr,i+1,arrSize);
        result[i] = max;
    }
    *returnSize = arrSize;
    return result;
}