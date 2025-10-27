bool isValid(char * s){
    char *parstack = malloc(102400);
    int n=0;
    
    if(NULL == s) return false;

    while(*s){
        switch(*s){
            case '(':
            case '{':
            case '[':
                parstack[n++] = *s;
                break;
            case ')':
                if(0 == n || parstack[--n] != '(') return false;            
                break;
            case '}':
                if(0 == n || parstack[--n] != '{') return false;
                break;
            case ']':
                if(0 == n || parstack[--n] != '[') return false;
                break;
            case ' ':
                break;
            default:
                return false;
                break;
        }
        s++;
    }
    
    free(parstack);
    return 0 == n;
}