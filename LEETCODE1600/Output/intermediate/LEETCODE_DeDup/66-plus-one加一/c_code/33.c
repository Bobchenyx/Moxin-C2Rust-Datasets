/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i, flag = 0;
    int *arr = NULL;

    for (i = digitsSize - 1; i >= 0; i--)
    {
        if (flag == 1 || i == digitsSize - 1)
        {
            if (digits[i] == 9) 
            {
                digits[i] = 0;
                flag = 1;
            }
            else
            {
                digits[i]++;
                flag = 0;
                break;
            }
        }
    }

    if (digits[0] == 0)
    {
        *returnSize = digitsSize + 1;
        arr = (int *)malloc(sizeof(int) * *returnSize);
        arr[0] = 1;
        memcpy(arr + 1, digits, sizeof(int) * digitsSize);
    } else
    {
        *returnSize = digitsSize;
        arr = (int *)malloc(sizeof(int) * *returnSize);
        memcpy(arr, digits, sizeof(int) * digitsSize);
    }
    return arr;
}