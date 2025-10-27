bool isValid(char * p)
{
    int len=strlen(p);
    if(len == 1)
        return 0;
    int top=1,i;
    char s[9999];  //堆栈存储
    for(i=0; i<len; i++)
    {
        switch(p[i])
        {
        case '(':
        case '[':
        case '{':
            s[top++]=p[i];
            break;
        case ')':
            if(s[top-1]=='(')
                top--;
            else return 0;
            break;
        case ']':
            if(s[top-1]=='[')
                top--;
            else return 0;
            break;
        case '}':
            if(s[top-1]=='{')
                top--;
            else return 0;
            break;
        }
    }
    if(top==1)
        return 1;  //输出1表示匹配成功
    else
        return 0;   //输出0表示匹配失败
}