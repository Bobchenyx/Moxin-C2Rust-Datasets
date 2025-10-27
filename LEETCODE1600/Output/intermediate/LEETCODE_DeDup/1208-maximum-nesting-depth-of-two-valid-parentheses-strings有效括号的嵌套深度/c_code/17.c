/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MMAX(a, b)      ((a) > (b)? (a) : (b))

//【算法思路】字符串。根据括号的出入栈情况，将不同深度的左右括号分别记录深度，并记录最大深度，然后取中间深度，将所有括号分为0,1两类
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int slen = strlen(seq);
    int ssize = 0;
    int *depth = (int *)calloc(slen, sizeof(int));

    int d = 0;
    int dmax = 0;

    for(int i = 0; i < slen; i++)
    {
        if(seq[i] == '(')
        {
            //当前深度增加
            d++;

            //当前深度赋值
            depth[i] = d;

            //刷新最大深度
            dmax = MMAX(dmax, d);
        }
        else
        {
            //当前深度赋值
            depth[i] = d;

            //当前深度减少
            d--;
        }
    }
/*
    for(int i = 0; i < slen; i++)
    {
        printf("<%d>%d ", i, depth[i]);
    }
    printf("\n");
*/
    int mid = dmax / 2;

    //printf("mid = %d\n", mid);

    for(int i = 0; i < slen; i++)
    {
        if(depth[i] <= mid)
        {
            depth[i] = 0;
        }
    }

    for(int i = 0; i < slen; i++)
    {
        if(depth[i] > mid)
        {
            depth[i] = 1;
        }
    }

    *returnSize = slen;
    return depth;
}