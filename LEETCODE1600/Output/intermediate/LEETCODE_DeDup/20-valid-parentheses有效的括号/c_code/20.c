bool isValid(char * s){
    int stack[5000];int top=-1;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(top==-1){
            stack[++top]=s[i];
            continue;
        }
        switch(s[i]){
            case ')':if(stack[top]=='('){top--;}else{stack[++top]=s[i];} break;
            case ']':if(stack[top]=='['){top--;}else{stack[++top]=s[i];} break;
            case '}':if(stack[top]=='{'){top--;}else{stack[++top]=s[i];} break;
            default:stack[++top]=s[i];
        }
    }
    if(top!=-1){
        return false;
    }else{
        return true;
    }
}