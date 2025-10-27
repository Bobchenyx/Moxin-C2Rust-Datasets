/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize)
{
    //入参检查
    if(numsSize %2 != 0)
    {
        return NULL;
    }

    //分配两个数组，分别存放原数组的奇数位元素和偶数位元素
    int num1[numsSize/2];
    int num2[numsSize/2];
    int m=0,n=0;
    int len = 0;
    for(int i =0; i<numsSize;i++)
    {
        if(i%2 == 0)
        {
            num1[m] = nums[i];
            len +=num1[m];//计算得出需要malloc数组的长度
            m++;
        }
        else
        {
            num2[n] = nums[i];
            n++;
        }
    }

    int *result = (int*)malloc(sizeof(int)*len);
    memset(result,0,sizeof(int)*len);

    int j =0;
    int index = 0;
    while(j<m)
    {
        for(int k =0;k< num1[j];k++)
        {
            result[index] = num2[j];
            index++;
        }
        j++;
    }
    *returnSize = len;
    return result;

}