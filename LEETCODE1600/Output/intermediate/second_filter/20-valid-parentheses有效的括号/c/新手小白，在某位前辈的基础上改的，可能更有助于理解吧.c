bool isValid(char * s){
    int len = strlen(s);
    if(len % 2 != 0){
        return false;
    }
    if(s == ""){
        return true;
    }
    char *stack = (char*)malloc(sizeof(char)*(len + 1));
    int top = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            stack[top++] = s[i];
        }else{
            top--;
            if(top < 0) return false;
            if(s[i] == '}' && stack[top] != '{') return false;
            if(s[i] == ']' && stack[top] != '[') return false;
            if(s[i] == ')' && stack[top] != '(') return false;
        }
    }
    if(top == 0){
        return true;
    }else{
        return false;
    }

}