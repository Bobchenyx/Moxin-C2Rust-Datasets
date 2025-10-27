bool isPalindrome(char * s){
    if (strlen(s) == 0) {
        return true;
    }
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 'a' - 'A';
        }
    }
    int normalLen = 0;
    char normal[strlen(s)];
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            normal[normalLen] = s[i];
            normalLen++;
        }
    }
    for (int i = 0, j = normalLen - 1; i < j; i++, j--) {
        if (normal[i] != normal[j]) {
            return false;
        }
    }
    return true;
}