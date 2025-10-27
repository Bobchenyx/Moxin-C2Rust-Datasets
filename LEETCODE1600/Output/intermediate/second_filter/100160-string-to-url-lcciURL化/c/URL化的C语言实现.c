char* replaceSpaces(char* S, int length)
{
    //入参检查
    if(S == NULL)
    {
        return NULL;
    }
    
    //遍历字符串，获取空格的个数
    int num = 0;
    int i =0;
    for(int i = 0;i<length;i++)
    {
        if(S[i] == ' ')
        {
            num++;
        }
    }

    int newlen = length + num*2;
    int j = newlen - 1;
    for(i=length-1; i>=0 && i != j; i--)
    {
        if(S[i] == ' ')
        {
            S[j--] = '0';
            S[j--] = '2';
            S[j--] = '%';
        }
        else
        {
            S[j--] = S[i];
        }
    }
    S[newlen] = '\0';
    return S;
}