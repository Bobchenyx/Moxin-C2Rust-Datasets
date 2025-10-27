/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
第一种方法就是一个个的分配深度，先给A，再给B，如果遇到两个符号不同，就说明是同一深度的，
如果两个符号相同，就说明不是同一深度的，这是应该给A,B轮流赋值
 */

int* maxDepthAfterSplit(char * seq, int* returnSize){
    int length = strlen(seq);
    int num = 0;
    *returnSize = length;
    int *ret = (int *)malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
    {
        if(i != 0 && seq[i] == seq[i-1])
        {
            num = 1 - num;
        }
            ret[i] = num;
    }
    return ret;
}