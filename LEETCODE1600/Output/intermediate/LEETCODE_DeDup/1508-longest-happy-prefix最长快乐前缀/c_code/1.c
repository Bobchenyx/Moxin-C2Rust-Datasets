char * longestPrefix(char * s){
    int i;
    int l = strlen(s);

    for (i = l - 1; i > 0; i--) {
        if (!memcmp(s, s + l - i, i)) {
            break;
        }
    }

    char *res = calloc(i + 1, sizeof(char));
    memcpy(res, s, i);
    return res;
}