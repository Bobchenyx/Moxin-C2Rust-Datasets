int myAtoi(char * str){
    int len = strlen(str);
    int MAX = 2147483647,MIN = -2147483648;
    int i = 0,re = 0;
    int flag = 1;
    while(i<len){
        if(str[i] == ' ')
            i++;
        else 
            break;
    }
    if(str[i]=='-'){
        flag = -1;
        i++;
        }
    else if(str[i] == '+')
        i++;
    else if(str[i]<='9'&&str[i]>='0');
    else return re;
    while(i<len){
        if(str[i]>'9'||str[i]<'0') break;
        if(re>MAX/10||(re==MAX/10&&(str[i]-'0')>=7)) return MAX;
        if(re<MIN/10||(re==MIN/10&&(str[i]-'0')>=8)) return MIN;
        if(flag == 1)
            re = re*10+(str[i]-'0');
        else
            re = re*10-(str[i]-'0');
        i++;
    }
    return re;
}