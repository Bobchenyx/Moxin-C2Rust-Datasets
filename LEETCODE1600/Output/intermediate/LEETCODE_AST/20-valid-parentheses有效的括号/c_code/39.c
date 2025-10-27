bool isValid(char * s){
    int idx = -1;
    char* p = s;
    while (*p) {
        switch (*p) {
            case '(':
            case '[':
            case '{':
                s[++idx] = *p;
                break;
            case ')':
                if (idx < 0) {
                    return false;
                }
                if (s[idx] == '(') {
                    idx--;
                } else {
                    return false;
                }
                break;
            case '}':
                if (idx < 0) {
                    return false;
                }
                if (s[idx] == '{') {
                    idx--;
                } else {
                    return false;
                }
                break;
            case ']':
                if (idx < 0) {
                    return false;
                }
                if (s[idx] == '[') {
                    idx--;
                } else {
                    return false;
                }
                break;
            default:break;
        }
        p++;
    }
    if (idx >= 0) {
        return false;
    } else {
        return true;
    }
}