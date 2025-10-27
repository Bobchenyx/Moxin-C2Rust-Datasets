//定义全局数组
#define MAXSIZE 20000
char result[MAXSIZE] = {0};

char* replaceSpace(char* s)
{
    //入参检查
    if(strlen(s) == 0)
    {
        return s;
    }

    //计算原数组的空格数
    int space = 0;
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i] == ' ')
        {
            space++;
        }
    }

    //初始化全局数组
    memset(result,0,20000);
    //计算替换空格后数组的长度
    int len = strlen(s) + space*2;
    int k =len-1;
    //循环遍历原数组，替换空格
    for(int j=strlen(s)-1; j>=0; j--)
    {
        if(s[j] == ' ')
        {
            result[k--] = '0';
            result[k--] = '2';
            result[k--] = '%';
        }
        else
        {
            result[k--] = s[j];
        }
    }
    return result;
}