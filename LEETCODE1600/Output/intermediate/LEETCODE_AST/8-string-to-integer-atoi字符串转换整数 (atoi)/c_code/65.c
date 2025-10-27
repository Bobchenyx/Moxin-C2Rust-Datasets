long res = 0;
    while((*str) != '\0' && isdigit(*str)) {
        ...
        if ((int)res != res) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        ...
    }