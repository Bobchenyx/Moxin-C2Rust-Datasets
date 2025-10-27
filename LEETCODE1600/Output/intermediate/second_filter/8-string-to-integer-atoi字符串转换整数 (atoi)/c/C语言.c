int myAtoi(char * str){
    int len = strlen(str);
    while(*str != '\0' && *str == ' ')str++;
    if(*str == '\0')return 0;
    bool flag = true;
    if(*str == '-'){
        flag = false;
        str++;
    }
    else if( *str == '+'){
        
        str++;
    }
    else if (*str > '9' || *str < '0'){
        return 0;
    }
    int ans = 0;
    while(*str != '\0'){
    if (*str > '9' || *str < '0')break;
    if(ans > (INT_MAX - (*str - '0')) / 10 )
        return flag ? INT_MAX : INT_MIN;
    ans = ans * 10 + (*str - '0');
    str++;
    }
    return flag ? ans : -ans;
}