char * freqAlphabets(char * s){
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char)*(len+1));
    int index = 0;


    for (int i=0; i<len; i++){ s[i] -= 48; }
    for (int i=0; i<len; i++){
        if ((i<len-2 && s[i+2]!= -13 )||i>len-3){
            res[index++] = s[i]+96;
        }
        else{
            res[index++] = 10*s[i]+s[i+1] + 96;
            i+=2;
            if (i == len-1) break;
        }
    }
    res[index] = '\0';
    return res;
}