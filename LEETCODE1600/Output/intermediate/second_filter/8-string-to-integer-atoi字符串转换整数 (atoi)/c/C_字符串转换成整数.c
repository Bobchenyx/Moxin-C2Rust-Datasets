int myAtoi(char* str) {
    //去除空格及判断符号位
    while(*str==' ')
        ++str;
    //默认正数
    int flag = 1;
    switch (*str)
    {
        case '-':flag = -1;
        case '+':str++;
    }
    //排除非数字的情况
    if (*str < '0' || *str>'9')
        return 0;

    long ret = 0;
    while (*str >= '0' && *str <= '9') {
        ret = ret * 10 + (*str - '0');
        //判断溢出
        if ((int)ret != ret)
            return (flag == 1) ? (INT_MAX) : (INT_MIN);
        str++;
    }
    ret *= flag;
    return (int)ret;
}