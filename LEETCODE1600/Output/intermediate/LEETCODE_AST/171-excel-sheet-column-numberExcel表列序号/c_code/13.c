int titleToNumber(char * s){
    int num;
    int ret = 0;
    for(int i = 0; i < strlen(s); i++){
        num = s[i] - 'A' + 1;
        ret = ret * 26 + num;
    }
    return ret;
}