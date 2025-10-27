#include <string.h>

char * reverseWords(char * s){
    int len = strlen(s);
    int count = 0;
    int flag = 0;//标记位
    char temp;
    int start;

    //首部空格去除
    for (int i = 0;i < len;i++)
    {
        if (s[i] != ' ')
        {
            s[count] = s[i];
            flag = 1;
            count++;
        }
        else
        {
            if (flag == 1)
            {
                s[count] = s[i];
                count++;
            }
        }
    }
    s[count] = '\0';

    //整体翻转
    len = strlen(s);
    for (int i = 0;i < len / 2;i++)
    {
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }

    //去掉现在头部的空格（原尾部）
    flag = 0;
    count = 0;
    for (int i = 0;i < len;i++)
    {
        if (s[i] != ' ')
        {
            s[count] = s[i];
            flag = 1;
            count++;
        }
        else
        {
            if (flag == 1)
            {
                s[count] = s[i];
                count++;
            }
        }
    }
    s[count] = '\0';

    //处理单词中间多余的空格
    len = strlen(s);
    flag = 0; //重复使用flag,用于标记是否多个空格重复
    count = 0;
    for (int i = 0;i < len;i++)
    {
        if (s[i] == ' ')
        {
            if (flag == 0)
            {
                s[count] = s[i];
                flag = 1;
                count++;
            }
        }
        else
        {
            s[count] = s[i];
            flag = 0;
            count++;
        }
    }
    s[count] = '\0';

    //局部翻转
    //此时中间的空格仅仅只剩下一个
    start = 0;
    len = strlen(s);
    for (int i = 0;i < len;i++)
    {
        if (s[i] == ' ')
        {   
            for (int j = start;j < (i + start) / 2;j++)
            {
                temp = s[j];
                s[j] = s[i - 1 - (j - start)];
                s[i - 1 - (j - start)] = temp;
            }
            start = i + 1;
        }
    }
    //处理一下尾部情况
    for (int i = start;i < (len + start) / 2;i++)
    {
        temp = s[i];
        s[i] = s[len - 1 - (i - start)];
        s[len - 1 - (i - start)] = temp;
    }

    return s;
}