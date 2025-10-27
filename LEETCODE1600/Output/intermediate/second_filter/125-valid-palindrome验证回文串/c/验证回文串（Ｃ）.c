bool isPalindrome(char * s){
    if(s == "")
        return 1;

    int len = strlen(s);
    char *stk = (char*)malloc(sizeof(char) * len);
    int top = -1, i;
    for(i = 0; i < len; i++){
        if(isupper(s[i])){
            stk[++top] = s[i] + 32;
        }
        else if(islower(s[i]) || isdigit(s[i])){
            stk[++top] = s[i];
        }
    }
    for(i = 0; i < len; i++){
        if(isupper(s[i])){
            char t = stk[top];
            if(s[i] + 32 != t)
                return 0;
            top--;
        }
        else if(islower(s[i]) || isdigit(s[i])){
            char t = stk[top];
            if(s[i] != t)
                return 0;
            top--;
        }
    }
    if(top >= 0)
        return 0;
    return 1;
}