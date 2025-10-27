int titleToNumber(char * s){
    int len = strlen(s);
    int i;
    int sum = 0;

    for(i = 0; i < len; i++) {
        sum *= 26;
        sum += (s[i] - 'A' + 1);
    }
    return sum;
}