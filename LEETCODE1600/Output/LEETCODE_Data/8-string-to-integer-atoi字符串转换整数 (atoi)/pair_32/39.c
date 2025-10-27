int myAtoi(char * str){
    int flag = 1, bit = 11, has0 = false;
    long num = 0;
    while (*str == ' ')
        str++;
    while (*str == '0') {
        str++;
        has0 = true;
    }     
    if (*str == '-' && !has0) {
        flag = -1;
        str++;
    } else if (*str == '+' && !has0) {
        str++;
    } else if (!(*str >= '0' && *str <= '9')) {
        return 0;
    } 
    while (*str == '0') {
        str++;
    }
    while (*str <= '9' && *str >= '0' && bit--) {
        num = num*10 + *str - '0';
        str++;
    }
    num *=flag;
    if (num < -2147483648) return -2147483648;
    else if (num > 2147483647) return 2147483647;
    return num;
}