int myAtoi(char * str){
    int val = 0;
    int flag = 1; // 1:positive -1:negative
    int i = 0, d;
    int max=2147483647, min=-2147483648;

    while(*str) {
        if ('0' <= *str && '9' >= *str) {
            // digit
            d = *str - '0';
            if (val > (max - d)/10) return max;
            if (val < (min + d)/10) return min;
            val = val*10 + d*flag;
            i++;
        } else if (i>0) {
            // no more non-digit symbol allowed after valid digit
            break;
        } else if (*str == '+' || *str == '-') {
            flag = (*str == '-')?-1:1;
            i++; // consider +/- as valid start of digit
        } else if (*str != ' ') {
            return 0;
        }

        str++;
    }

    return val;
}