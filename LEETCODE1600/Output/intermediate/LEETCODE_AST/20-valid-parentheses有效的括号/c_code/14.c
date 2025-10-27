bool isValid(char * s){
    int len = 1,k=0;
    char *str;
    while(*s++!='\0')len++;
    s-=len;
    str = (char*)malloc(sizeof(char)*len);
    str[k]=s[0];
    for(int i=1;i<len;i++){
        if(k>-1&&(s[i]==')'&&str[k]=='('||s[i]==']'&&str[k]=='['||s[i]=='}'&&str[k]=='{'))k--;
        else str[++k] = s[i];
    }
    if(str[0]=='\0')return true;
    return false;
}