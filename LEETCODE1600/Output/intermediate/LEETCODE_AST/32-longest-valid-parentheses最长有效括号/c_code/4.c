void findMatch(char *s, int index)
{
    int i;
    for (i = index - 1; i >= 0; i--) {
        if (s[i] == '(') {
            s[i] = '0';
            s[index] = '0';
            break;
        }
    }
    return;
}

int longestValidParentheses(char * s){
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == ')') {
            findMatch(s, i);
        }
    }
    int count = 0;
    int max = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == '0') {
            count++;
        } else {
            if (max < count) {
                max = count;
            }
            count = 0;
        }
    }
    if (max < count) {
        max = count;
    }

    return max;
}