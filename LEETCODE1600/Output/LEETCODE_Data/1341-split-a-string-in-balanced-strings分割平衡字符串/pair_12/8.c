int balancedStringSplit(char * s){
    int length=0;
    for(char*iter =s;*iter!='\0';++iter)
        ++length;

    char *stack=(char*)malloc(sizeof(char)*(length+1));
    int top=-1;

    int sum=0;
    while(*s!='\0')
    {
        stack[++top]=*s++;
        while(top!=-1)
        {
            if(stack[top]==*s)
                stack[++top]=*s;
            else
                top--;
            ++s;            
        }
        ++sum;
    }

    free(stack);

    return sum;
}