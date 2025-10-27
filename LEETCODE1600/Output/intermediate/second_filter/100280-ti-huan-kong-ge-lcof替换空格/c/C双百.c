char* replaceSpace(char* s)
{
    int i = 0;
    int space = 0;
    int len = strlen(s);
    while(s[i] != '\0')
    {
        if(s[i] == ' ')
        {
            space++;
        }
        i++;
    }
    s = (char* )realloc(s, sizeof(char) * (len  + 2 * space + 1));              //为s重新申请内存空间
    int newlen = len + 2 * space;
    s[newlen--] = '\0';
    i = len -1;
    while(i >= 0)
    {
         if(s[i] != ' ')
         {
             s[newlen--] = s[i];
         }
         else
        {
             s[newlen--] = '0';
             s[newlen--] = '2';
             s[newlen--] = '%';
        }
        i--;
    }
    return s;
}