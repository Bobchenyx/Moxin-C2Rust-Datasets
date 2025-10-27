bool isValid(char * s) {
    int top = 0;
    int size;
    bool bValid = true;
    char *stack = NULL;
    
    if (*s == '0') {
        return true;
    }

    size = strlen(s);
    if ((size % 2) != 0) {
        return false;
    }

    stack = malloc(size);

    for (int i = 0; i < size; i++) {
        if (s[i] == '(' ) {
            stack[top] = ')';
            top++;
        } else if (s[i] == '[') {
            stack[top] = ']';
            top++;
        } else if (s[i] == '{') {
            stack[top] = '}';
            top++;
        } else if (top > 0 && stack[top - 1] == s[i]) {
            top--;
            stack[top] = 0;
        } else {
            bValid = false;
            break;
        }
    }
    
    if (top > 0) {
        bValid = false;
    }

    free(stack);
    stack = NULL;

    return bValid;
}