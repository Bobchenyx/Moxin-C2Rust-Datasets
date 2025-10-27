/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int num;
    num = digitsSize;
    digits[digitsSize - 1]++;
    for(int i = digitsSize - 1; i >= 0; i--)  //判断加一之后数的位数
    {                                          
        if(digits[0] == 10)   
        {
           num = digitsSize + 1;
            break;
        }
        else if(digits[i] == 10 && i != 0) //防止输入9 数组越界
        {
            digits[i] = 0;
            digits[i - 1]++;
        }
        
        else break;
    }
    *returnSize = num;
    int *new = (int *)malloc(sizeof(int) * num);
    if(num > digitsSize)
    {
        new[0] = 1;
        for(int i = 1; i <= digitsSize; i++)
        {
            new[i] = 0;
        }
    }
    else if(num == digitsSize)
    {
        for(int i = 0; i < digitsSize; i++)
        {
            new[i] = digits[i];
        }
    }
    return new;

}