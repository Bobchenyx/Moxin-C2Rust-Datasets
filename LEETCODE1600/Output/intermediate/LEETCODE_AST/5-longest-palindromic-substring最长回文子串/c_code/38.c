char * longestPalindrome(char * s){
    int len  = strlen(s);
    int m, n, i, j;
    int maxCur = 0;
    int maxMax = 0;
    char *retChar = (char*)malloc(sizeof(char) * (len * 2 + 1));
    memset(retChar, 0, (len * 2 + 1));
    for (m = 0; m < len; m++) {
        n = len - 1;
        i = m;
        j = n;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                n--;
                i = m;
                j = n;
            }
        }
        maxCur = n - m + 1;
        if (maxMax < maxCur) {
            maxMax = maxCur;
            strncpy(retChar, (s + m), maxMax);
            retChar[maxMax] = 0;
        }
    }
    
    return retChar;
}