int longestPalindrome(char * s){
    int arry[26 * 2] = {0};
    if (s == NULL) {
        return 0;
    }
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            arry[26 + s[i] - 'A']++;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            arry[s[i] - 'a']++;
        }
    }
    int retlen = 0;
    int hava = 0;
    for (int i = 0; i < 26 * 2; i++) {
        if (arry[i] % 2) {
            hava = 1;
            retlen += arry[i] - 1;
        } else {
            retlen += arry[i];
        } 
    }
    if (hava)
        retlen++;
    return retlen;
}