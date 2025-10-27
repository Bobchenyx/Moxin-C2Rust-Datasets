/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = digitsSize - 1;//从0开始计数
    for(i;i>=0;i--){
        if(digits[i]<9){//如果小于9直接加1
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i]=0;//否则这一位置为0，然后判断下一位，下一位加1
    }
    //如果进行到这一步说明为全9 如：99，999，9999等
    //需要多分配一位来容纳 如：99+1=100 变成三位数
    // aaa = malloced(sizeof(int * digitsSize + 1));写的什么狗屁分配函数
    int* result = (int*) malloc ((digitsSize+1) * sizeof(int));//一定要有括号括起来！！
    result[0]=1;//第一位是1，其余位为0.参看100即可
    for(i=1;i<=digitsSize;++i) result[i]=0;
    *returnSize = digitsSize + 1;
    return result;
}