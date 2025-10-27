int romanToInt_single(char *s, int index, int sSize, int *flag){
    // 这里的条件防止贪心访问越界
    if (index+1 < sSize){
        if (s[index] == 'I' && s[index+1] == 'V') {*flag = 1; return 4;}
        else if(s[index] == 'I' && s[index+1] == 'X') {*flag = 1; return 9;}
        else if(s[index] == 'X' && s[index+1] == 'L') {*flag = 1; return 40;}
        else if(s[index] == 'X' && s[index+1] == 'C') {*flag = 1; return 90;}
        else if(s[index] == 'C' && s[index+1] == 'D') {*flag = 1; return 400;}
        else if(s[index] == 'C' && s[index+1] == 'M') {*flag = 1; return 900;
    }}
    if (s[index] == 'I') {*flag = 0; return 1;}
    else if (s[index] == 'V') {*flag = 0; return 5;}
    else if (s[index] == 'X') {*flag = 0; return 10;}
    else if (s[index] == 'L') {*flag = 0; return 50;}
    else if (s[index] == 'C') {*flag = 0; return 100;}
    else if (s[index] == 'D') {*flag = 0; return 500;}
    else if (s[index] == 'M') {*flag = 0; return 1000;}
    return ;
}

int romanToInt(char * s){
    int len = strlen(s);
    int res =  0, temp;
    int flag = 0;
    for (int i=0; i<len; i++){
        temp = romanToInt_single(s, i, len, &flag);
        res += temp;
        if (flag){ i++; }
    }
    return res;
}