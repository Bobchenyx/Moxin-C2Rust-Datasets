int firstUniqChar(char * s){
    int* hash = (int*)malloc(sizeof(int) * 26);
    memset(hash, 0, sizeof(int) * 26);
    int i;
    int len = strlen(s);
    for(i = 0; i < len; i++) {
        hash[s[i] - 'a']++;
    }
    for(i = 0; i < len; i++) {
        if(hash[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}