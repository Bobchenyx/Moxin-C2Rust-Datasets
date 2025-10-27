int strtop;
int scoreOfParentheses(char * S){
    if (S == NULL || S[0] == '\0') return 0;
    int len = strlen(S);
    strtop = 0;
    int sum = 0;
    while (strtop < len) sum += find(S);//对于这种情况：()()()
    return sum;
}
int comp_sum(char *str) //计算子括号的值
{
    int sum = 0;
    ++strtop;
    while (str[strtop] == '(') sum += comp_sum(str);//对于这种情况：(()()())
    ++strtop;
    return (sum ? 2*sum : 1);//如果sum不等于0，那么乘以2，否则为1
}