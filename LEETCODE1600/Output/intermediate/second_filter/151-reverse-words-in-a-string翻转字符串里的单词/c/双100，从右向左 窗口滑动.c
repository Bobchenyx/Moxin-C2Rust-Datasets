char * reverseWords(char * s){
    if (s == NULL) {
        return NULL;
    }
    int len  = strlen(s);
    char *out = malloc (len + 1);
    memset(out, 0, len + 1);

    if (strchr(s, ' ') == NULL) {
        strcpy(out, s);
        return out;
    }

    int i = len - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    if (i == -1) {
        return out;
    }
    char *m = out;

    int l = -1;
    int r = i;
    //printf("r new:%d\n", r);
    int flag = 0;
    for (; i >= 0; i--) {
        if (s[i] != ' ') {
            continue;
        }

        l = i;
        int cplen = r - l;
        //printf("pl:%s,cplen:%d\n", &s[l],cplen);
        memcpy(m, s + l + 1, cplen);
        m += cplen;
        *(m++) = ' ';
        //printf("out:%s\n", out);
        while (i >= 0 && s[i] == ' ') {
            i--;
            r = i;
        }
        if (i == -1) {
            break;
        }
        //printf("new r :%d\n", r);
    }

    if (r >= 0) {
        int cplen = r + 1;
        memcpy(m, s, cplen);
        m += cplen;
        //printf("out:%s\n", out);   
    } else if (m > 0) {
        *(m - 1) = '\0';
    }

    return out;
}