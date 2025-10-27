int myAtoi(char * str){
    long ret=0;
    int i=0;
    int flag=1;
    while(str[i]==' ') i++;
    if(str[i]=='-') flag=-1;
    if(str[i]=='-'||str[i]=='+') i++;
    if('0'<=str[i]&&str[i]<='9')
    {
        int j=i+1;
        while(('0'<=str[j]&&str[j]<='9')&&j<strlen(str)) j++;
        for(int t=i;t<j;t++)
        {
            ret=ret*10+str[t]-'0';
            if(flag*ret>INT_MAX)
                return INT_MAX;
            if(flag*ret<INT_MIN)
                return INT_MIN;
            continue;
        }      
    }
    else
        return 0;
    return ret*flag;
}