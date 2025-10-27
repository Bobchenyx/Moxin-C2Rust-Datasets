int myAtoi(char * str)
{
    int flag = 0;       //  正负标记位
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')      
        {
            continue;           //先过滤开头的空格
        }
        if (str[i] == '-' || str[i] == '+')
        {
            if (str[i] == '-')
            {
                flag = 1;
            }
            i++;
        }
        int len = 0, start = 0;  //记录数字序列的起始位置和连续长度
        for (start = i;(str[i] >= '0' && str[i] <= '9') && str[i] != '\0'; i++)
        {
            len++;          //记录连续数字长度
        }
        if (!len)
        {
            return 0;        //数字长度为0，就说明第一个碰到的不是数字，返回0
        }
        int temp = 0;
        for (int j = start; len > 0; j++, len--)
        {
        /*    if (str[start] == '0' && len > 1)
            {
                return 0;        //首位为0，不能转换
            }     */             //这段我注释掉了，因为力扣测试首位可以为0
            if (temp > INT_MAX / 10 || (temp == INT_MAX / 10 && (int)(str[j] - '0') > 7))
            {
                return INT_MAX;    //这里的溢出判断参考力扣第7题
            }
            if (temp < INT_MIN / 10 || (temp == INT_MIN / 10 && ~(int)(str[j] - '0') + 1 < -8))
            {
                return INT_MIN;
            }
            if(flag)        //一个数取相反数的办法是按位取反 + 1
            {
                temp = ~(int)(str[j] - '0') + 1 + temp * 10;
            }
            else
            {
                temp = (int)(str[j] - '0') + temp * 10;
            }
        }
        return temp;
    }
    return 0;
}