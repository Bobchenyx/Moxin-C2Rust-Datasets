int myAtoi(char * str)
{
    int i = 0, r = 0, sign = 1;
    while (isspace(str[i])) ++i;     /* 跳过开头的空格 */
    if (str[i] == '-') {                /* 负号 */
        sign = -1;
        ++i;
    }
    else if (str[i] == '+')            /* 正号 */
        ++i;
    if (!isdigit(str[i]))          /* str[i] 不是数字字符，返回0 */
        return 0;
    for (; isdigit(str[i]); ++i) {
        if(r < INT_MAX/10 || (r == INT_MAX/10 && str[i]-'0' < 8))    /* 判断r是否溢出 */
            r = r * 10 + (str[i]-'0');
        else
            return sign == 1 ? INT_MAX : INT_MIN;
    }
    return r * sign;
}