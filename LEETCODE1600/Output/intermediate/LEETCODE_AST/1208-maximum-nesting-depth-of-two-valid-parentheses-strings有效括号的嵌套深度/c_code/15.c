/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize)
{
    int len = strlen(seq);
    if(len % 2 == 1 || seq[0] == ')' || seq[len - 1] == '(')
    {
        return 0;
    }
    * returnSize = len;

    int status = 0;
    int * res = (int *)malloc(len * sizeof(int));
    res[0] = 0;
    for(int i = 1; i < len; i++)
    {
        if(seq[i] != seq[i -1])
        {
            res[i] = res[i-1];
        }
        else
        {
            res[i] = !res[i-1];
        }
    }
    return res;

}