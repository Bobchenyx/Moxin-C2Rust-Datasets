int myAtoi(char * str){
    int i = 0;
    int unflag = 1;
    long num = 0;
    int max = 0x7fffffff;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        if ((str[i] == '-') || (str[i] == '+')) {
            unflag = (str[i] == '-') ? -1 : 1;
            i++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            unflag = 1;
        } else {
            return 0;
        }

        while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
            if ((num * unflag > max) || (num * unflag < (-1 * (max + 1)))) {
                return unflag == 1 ? max : -1 * (max + 1);
            }
            i++;
        }
        return unflag * num;
    }
    return unflag * num;
}