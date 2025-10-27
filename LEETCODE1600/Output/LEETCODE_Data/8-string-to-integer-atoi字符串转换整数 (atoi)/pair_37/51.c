int myAtoi(char * str){
    int len = strlen(str);
    int begin, end;
    int i;
    int flag = 0;
    long num = 0;
    int temp = 0;

    if (len == 0) {
        return 0;
    }

    // 找到第一个不是空格的位置
    for (begin = 0; begin < len; begin++) {
        if (isspace(str[begin]) != 0) {
            continue;
        }

        break;
    }

    if (begin < len) {
        if (str[begin] == '+') {
            flag = 1;
        }

        if (str[begin] == '-') {
            flag = -1;
        }

        if (flag == -1 || flag == 1) {
            begin++;
        }
    }

    for (i = begin; i < len; i++) {
        // 找到第一个不是数字的位置
        if (isdigit(str[i]) != 0) {
            continue;
        }

        break;
    }

    end = i;

    for (i = begin; i < end; i++) {
        temp = str[i] - '0';

        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && temp > 7)) {
            return flag == -1 ? INT_MIN : INT_MAX;
        }

        num = num * 10 + temp;
    }

    if (flag == -1) {
        num *= flag;
    }

    return num;
}