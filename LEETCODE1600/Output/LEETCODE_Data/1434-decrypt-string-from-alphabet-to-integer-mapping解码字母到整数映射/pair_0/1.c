char * freqAlphabets(char * s){
    char *sTemp = (char *)calloc(strlen(s), sizeof(char)+1); 
    int i = 0;
    int j = 0;
    for(i = 0;i < strlen(s);) {
        if((i+2) < strlen(s) && s[i + 2] == '#') {
            sTemp[j] = ((s[i] - '0') * 10 + s[i + 1] - '0') + 96;
            i = i + 3;
        } else {
            sTemp[j] = (s[i] - '0') + 96;
            i++;
        }
        j++;
    }
    for(i = 0; i <= strlen(sTemp); i++) {
        s[i] = sTemp[i];
    }

    return sTemp;
}