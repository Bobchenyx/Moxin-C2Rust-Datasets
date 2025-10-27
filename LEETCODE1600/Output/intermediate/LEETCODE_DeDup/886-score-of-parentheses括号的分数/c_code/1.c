#define LVL_SIZE    1000
#define STK_SIZE    1000

int stk[STK_SIZE];

// 【算法思路】栈或dfs。使用栈实现。注意，栈隐含着层级的概念，预先定义多层和，使用栈记录括号层级，“（”增加一层，“）”进行本层的结算，最终得到结果
int scoreOfParentheses(char * S){
    int * lvl_sum = (int *)calloc(LVL_SIZE, sizeof(int));

    int slen = strlen(S);
    int ssize = 0;

    for(int i = 0; i < slen; i++)
    {
        if(S[i] == '(')
        {
            stk[ssize++] = i;
        }
        else
        {
            ssize--;

            int lvl = ssize;

            if(lvl_sum[lvl + 1] != 0)
            {
                lvl_sum[lvl] += lvl_sum[lvl + 1] * 2;
                lvl_sum[lvl + 1] = 0;
            }
            else
            {
                lvl_sum[lvl]++;
            }

            //printf("lvl_sum[%d] = %d\n", lvl, lvl_sum[lvl]);
        }
    }

    return lvl_sum[0];
}