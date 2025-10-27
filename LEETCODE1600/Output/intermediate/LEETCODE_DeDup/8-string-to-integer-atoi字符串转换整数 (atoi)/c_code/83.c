int myAtoi(char * str){
    int n = strlen(str);
    char *tmp = (char *)malloc(sizeof(char)*(n + 1));
    memset(tmp, '\0', sizeof(char)*(n + 1));
    int i = 0, k = 0;
    for(int i = 0 ; i < n; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            tmp[k++] = str[i];
        } 
        else if(str[i] == '+' || str[i] == '-' && strlen(tmp) == 0){
            tmp[k++] = str[i];
        } 
        else if(str[i] == ' ' && strlen(tmp) == 0){
            continue;
        }
        else{
            break;
        }
    }
    tmp[k] = '\0';
    long long num = atoll(tmp);
    if(num > INT_MAX ) return INT_MAX;
    else if(num < INT_MIN) return INT_MIN;
    else return num;
}