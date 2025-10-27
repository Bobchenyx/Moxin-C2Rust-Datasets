bool isValid(char * s){
    int len = strlen(s);
    if (len % 2) return false;
    char *stack = (int *) malloc (sizeof(char) * len);
    int top = -1;
    int i;
    for(i = 0; i < len; i++) {
        if (s[i] == ')') {
            if (top < 0  ||  stack[top--] != '(') return false;
        }
        else if (s[i] == '}') {
            if (top < 0 || stack[top--] != '{') return false;
        }
        else if (s[i] == ']' ) {
            if (top < 0 || stack[top--] != '[') return false;
        }
        else  stack[++top] = s[i];
    }
    return top == -1 ? true : false;
}