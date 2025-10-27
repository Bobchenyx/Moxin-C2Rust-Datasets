int lengthOfLastWord(char * s){
    if (s == NULL) {
        return 0;
    }
    int sLen = strlen(s);
    int i;
    int tmpPos;
    for (i = sLen - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            tmpPos = i;
            break;
        }
    }

    for (i = tmpPos; i >= 0; i--) {
        if (s[i] == ' ') {
            return tmpPos - i;
        }
    }
    return tmpPos + 1;
}