int longestPalindrome(char * s){
    int len = 0;
    int flag = 0;
    int num[52] = {0};
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            num[s[i] - 'a']++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            num[s[i] - 'A' + 26]++;
        }
    }
    for (int i = 0; i < 52; i++) {
        len += num[i] / 2 * 2 ;
        if (num[i] % 2) {
            flag++;
        }
        if (num[i] != 0) {
        }
    }
    
    len = flag ? len + 1 : len;
    return len;
}