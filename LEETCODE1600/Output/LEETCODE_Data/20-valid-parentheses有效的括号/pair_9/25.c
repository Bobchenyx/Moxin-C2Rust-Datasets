bool isValid(char * s){
    int l = strlen(s);
    if(l==0)
        return true;
    if(l%2)
        return false;
    int top = 0;
    int* stack = (int*)malloc(l * sizeof(int));
    for(int i = 0;i < l;i++){
        switch(s[i]){
            case('('): stack[top++] = s[i];break;
            case('{'): stack[top++] = s[i];break;
            case('['): stack[top++] = s[i];break;
            case(')'):if(top == 0)  return false;
                    else if(stack[top-1] == '(') {top--; break;}
                    else  return false;
            case('}'):if(top == 0)  return false;
                    else if(stack[top-1] == '{') {top--; break;}
                    else  return false;
            case(']'):if(top == 0)  return false;
                    else if(stack[top-1] == '[') {top--; break;}
                    else  return false;
            default: return false;
        }
    }
    if(top > 0)
        return false;
    return true;
}