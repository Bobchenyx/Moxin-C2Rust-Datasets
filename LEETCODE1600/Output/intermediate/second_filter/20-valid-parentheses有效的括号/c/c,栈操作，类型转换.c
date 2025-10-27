char stack[10005];
bool isValid(char * s){
    int i;
    int len = 0;
    for(i = 0; s[i]; i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
        	len++;
            stack[len] = s[i];
        }
        else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if((int)(s[i] - stack[len]) < 3 && (int)(s[i]-stack[len]) > 0) len--;
            else return false;
        }
    }
    if(len == 0) return true;
    else return false;
}