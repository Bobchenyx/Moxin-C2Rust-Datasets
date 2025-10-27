bool backspaceCompare(char * S, char * T) {
    char *sStack = NULL;
    char *tStack = NULL;
    int slen = strlen(S);
    int tlen = strlen(T);
    sStack = (char *)malloc(sizeof(char) * (slen + 1));
    memset(sStack, '\0', sizeof(char) * (slen + 1));
    tStack = (char *)malloc(sizeof(char) * (tlen + 1));
    memset(tStack, '\0', sizeof(char) * (tlen + 1));
    int i, tops, topt;
    i = tops = topt = 0;
    while (i < slen || i < tlen) {
        if (i < slen) {
            if (S[i] != '#') {
                sStack[tops++] = S[i];
            } else {
                if (tops <= 0) {
                    // do nothing
                    tops = 0;
                } else {
                    tops--;
                }
            }
        }
        if (i < tlen) {
            if (T[i] != '#') {
                tStack[topt++] = T[i];
            } else {
                if (topt <= 0) {
                    // do nothing
                    topt = 0;
                } else {
                    topt--;
                }
            }
        }
        i++;
    }
    sStack[tops] = '\0';
    tStack[topt] = '\0';
    if (strcmp(sStack, tStack) == 0) {
        return true;
    }
    return false;
}