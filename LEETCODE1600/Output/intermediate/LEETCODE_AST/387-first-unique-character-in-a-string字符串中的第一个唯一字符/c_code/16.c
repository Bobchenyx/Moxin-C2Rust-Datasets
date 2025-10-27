int firstUniqChar(char * s){
    int i, len = strlen(s);
    int p[26];
    memset(p, 0, sizeof(int) * 26);
   
    for(i = 0; i < len; i++){
        p[s[i] - 'a']++;
    }
    for(i = 0; i < len; i++){
        if(p[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}