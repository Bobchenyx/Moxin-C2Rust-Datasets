int firstUniqChar(char * s){
    int alpha[26] = {0};
    for(int i = 0; i < strlen(s); i++){
        alpha[s[i]-'a']++;
    }
    for(int i = 0; i < strlen(s); i++){
        if(alpha[s[i]-'a'] == 1){
            return i;
        }
    }
    return -1;
}