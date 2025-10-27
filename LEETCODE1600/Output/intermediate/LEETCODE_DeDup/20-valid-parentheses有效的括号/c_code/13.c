bool isValid(char * s){
    int len=strlen(s);
    int a[10001]={0};
    int top=0;
    for (int i=0;i<len;i++){
        if(s[i]=='('){
            a[top++]=1;
            continue;
        }
        if(s[i]=='{'){
            a[top++]=3;
            continue;
        }
        if(s[i]=='['){
            a[top++]=2;
            continue;
        }
        if(s[i]==')'){
            if(top>=1&&a[top-1]==1){
                top--;
                continue;
            }
            return false;
        }
        if(s[i]==']'){
            if(top>=1&&a[top-1]==2){
                top--;
                continue;
            }
            return false;
        }
        if(s[i]=='}'){
            if(top>=1&&a[top-1]==3){
                top--;
                continue;
            }
            return false;
        }
    }
    if(top!=0)return false;  //特判
    return true;
}