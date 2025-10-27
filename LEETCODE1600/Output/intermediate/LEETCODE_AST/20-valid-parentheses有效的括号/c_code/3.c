bool isValid(char * s)
{
    if(s == NULL)return false;
    if(strlen(s) == 0)return true;//空字符串的判断
    int len = strlen(s);
    if(len%2!=0)return false;
    char *stack = (char*)malloc(sizeof(char)*len);
    int i,j;
    for(i=0,j=0;i<len;i++)
    {
        switch(s[i])
        {
            case '(':
            case '[':
            case '{':
                stack[j++] = s[i]; break;
            case ')':
                if(j > 0 && stack[--j]=='(')break;
                else return false;
            case '}':
                if(j > 0 && stack[--j]=='{')break;
                else return false;
            case ']':
                if(j > 0 && stack[--j]=='[')break;
                else return false;
            default:
                return false;
        }
    }
    if(j!=0)return false;
    else return true;
}