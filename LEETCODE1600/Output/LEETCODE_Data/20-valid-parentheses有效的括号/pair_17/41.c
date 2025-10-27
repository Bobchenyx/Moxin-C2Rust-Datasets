bool isValid(char * s){
    int len,i;
    len=strlen(s);
    if(len==0) return true;
    char stack[len];
    int top=-1;
    printf("%d \n",top);
    for(i=0;i<len;i++){
        switch (s[i]){
            case '(':
            case '[':
            case '{':   
                top++;
                stack[top]=s[i];
                break;
            case ')':
            case ']':
            case '}':  
                if(top>-1&&((s[i]-1)==stack[top]||(s[i]-2)==stack[top])){
                    top--;
                }else {
                    return false;

                }
        }
        printf("%d ",top);
    }
    if(top==-1){
        return true;
    }
    return false;

}