bool isValid(char * s){
    if(s[0]=='\0')
        return true;
    int n=strlen(s);
    int i=0;
    char str[n],st;
    int top=-1;
    while(s[i]!='\0')
    {
        st=s[i];
        switch(s[i])
        {
            case '(':top++;str[top]=st;break;
            case ')':
             if(top==-1)//防止出现第一个元素就是该值的可能，下面同理
            {
                top++;
                str[top]=st;
                break;
            }
            if(str[top]=='(')
            {
                top--;
                break;
            }
            else
            {
                top++;
                str[top]=st;
                break;
            }
            case '[':top++;str[top]=st;break;
            case ']':
            if(top==-1)
            {
                top++;
                str[top]=st;
                break;
            }
            if(str[top]=='[')
            {
                top--;
                break;
            }
            else
            {
                top++;
                str[top]=st;
                break;
            }
            case '{':top++;str[top]=st;break;
            case '}':
            if(top==-1)
            {
                top++;
                str[top]=st;
                break;
            }
            if(str[top]=='{')
            {
                top--;
                break;
            }
            else
            {
                top++;
                str[top]=st;
                break;
            }
        }
        i++;
    }
    if(top==-1)
        return true;
    else
        return false;
}