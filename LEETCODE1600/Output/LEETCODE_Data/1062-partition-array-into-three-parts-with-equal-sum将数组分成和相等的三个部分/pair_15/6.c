int arr_sum(int *A, int start, int end)
{
    int sum = 0;
    if(start < end)
    {
        for(int i = start; i<=end;i++)
        {
            sum+=A[i];
        }
    }
    return sum;
}

bool canThreePartsEqualSum(int* A, int ASize)
{
    /* 入参检查 */
    if(ASize == 0)
    {
        return true;
    }

    /* 计算整个数组的和 */
    int sum = arr_sum(A, 0, ASize-1);

    /* 计算sum/3的第一个下标 */
    int sum_i = 0;
    int i = 0;
    for( i= 0; i < ASize; i++)
    {
        sum_i += A[i];
        if(sum_i == sum/3)
        {
            break;
        }
    }

    /* 计算sum/3的第二个下标 */
    int sum_j = 0;
    int j = 0;
    for(j = i+1; j < ASize;j++)
    {
        sum_j += A[j];
        if(sum_j == sum/3)
        {
            break;
        }
        //printf("%d\n",sum_j);
    }

    if(j < ASize-1)
    {
        return true;
    }
    return false;
}