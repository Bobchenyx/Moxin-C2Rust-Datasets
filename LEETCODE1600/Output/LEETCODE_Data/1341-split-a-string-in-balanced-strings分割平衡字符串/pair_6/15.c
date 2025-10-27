int balancedStringSplit(char * s){
    int len = strlen(s);

    int* t = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++){
        if (s[i] == 'R')
            t[i] = 1;
        else
            t[i] = -1;
    }
    int sum = t[0], cnt = 0;
    for (int i = 1; i < len; i++){
        sum += t[i];
        if (sum == 0)
            cnt++;
    }
    return cnt;
}