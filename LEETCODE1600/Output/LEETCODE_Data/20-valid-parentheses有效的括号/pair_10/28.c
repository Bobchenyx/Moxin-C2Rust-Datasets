bool isValid(char * s)
{
    if (s == NULL) {
        return true;
    }

    int len = strlen(s);

    if (len % 2) {
        return false;
    }

    char *stack = (char *)malloc(len);
    memset(stack, 0, len); // 初始化栈为0
    int idx = -1; // 栈顶元素索引，起始没有元素

    for (int i = 0; i < len; i++) {
        //printf("idx=%d, %c\n", idx, s[i]); 
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            idx++;
            stack[idx] = s[i]; // 入栈，并维护索引
            //printf("push idx=%d, %c, %c\n", idx, stack[idx], s[i]);          
        } else if (idx == -1) {
            return false;
        } else if ((stack[idx] == '(' && s[i] == ')') || 
                   (stack[idx] == '[' && s[i] == ']') ||
                   (stack[idx] == '{' && s[i] == '}')) {
            stack[idx] = 0; // 出栈，维护索引
            //printf("pop idx=%d, %c, %c\n", idx, stack[idx], s[i]);
            idx--;        
        }
    }

    free(stack);
    
    if (idx == -1) {
        return true;
    }

    return false;
}