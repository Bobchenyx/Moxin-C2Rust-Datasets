inline void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void reverse(char *l, char *r) {
    r--;
    while (l < r) {
        swap(l, r);
        l++; r--;
    }
}
char * reverseWords(char * s){
    char *p = s;
    char *l;
    char *cur = s;
    char *end = s;

    l = NULL;
    while (*p != '\0') {
        if (l == NULL) {
            if (*p != ' ') {
                l = cur;
                *cur++ = *p;
            }
        } else {
            if (*p == ' ') {
                reverse(l, cur);
                l = NULL;
                end = cur;
            }
            *cur++ = *p;
        }
        p++;
    }
    if (l != NULL) {
        reverse(l, cur);
        end = cur;
    }

    reverse(s, end);
    *end = '\0';

    return s;
}