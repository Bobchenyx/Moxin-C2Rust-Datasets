bool isValid(char * s){
    if(s==NULL||s[0]=='\0')    return true;
    int top=0;
    char *stack=(char*)malloc(strlen(s)+1);
    for(int i=0;s[i];i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            stack[top++]=s[i];
        else
        {
            if((--top)<0)      return false;  //栈顶到栈尾
            if((s[i]==')'&&stack[top]!='(')||(s[i] == ']' && stack[top] != '[')||(s[i] == '}' && stack[top] != '{'))
                return false;
        }
    }
    return (!top);               //全不为括号情况
}