int longestPalindrome(char * s){
    if (s == NULL || strlen(s) == 0) {
        return 0;
    }

    int A[26] = {0};
    int a[26] = {0};
    char *tmp = s;

    while (*s != '\0') {
        if (*s >= 'A' && *s <= 'Z') {
            A[*s - 'A']++;
        }
        else {
            a[*s - 'a']++;
        }
        s++;
    }

    int i;
    int res = 0;
    int flag = 0;

    for (i = 0; i < 26; i++) {
        if (A[i] % 2) {
            flag = 1;
            res += (A[i] - 1);
        }
        if (a[i] % 2) {
            flag = 1;
            res += (a[i] - 1);
        }
        if (A[i] % 2 == 0) {
            res += A[i];
        }
        if (a[i] % 2 == 0) {
            res += a[i];
        }
    }

    //printf("res = %d, min = %d\n", res, min);
    res += flag;

    return res;
}