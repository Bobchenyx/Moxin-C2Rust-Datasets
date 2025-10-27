#define CHARNUM 26
char * sortString(char * s){
    // 按照字母个数进行存储
    // for循环，正向和反向查找
    int i, j, len;
    int *cnt = (int *)malloc(CHARNUM * sizeof(int));
    memset(cnt, 0, CHARNUM * sizeof(int));
    len = strlen(s);
    i = len;
    while (i--) {
        cnt[s[i] - 'a']++;
    }
    //正向及反向查找
    for (i = 0; i < len;) {
        for (j = 0; j < CHARNUM && i < len; j++) {
            if (cnt[j] > 0) {
                s[i++] = j + 'a';
                cnt[j]--; 
            }
        }
        for (j = CHARNUM - 1; j >= 0 && i < len; j--) {
            if (cnt[j] > 0) {
                s[i++] = j + 'a';
                cnt[j]--;
            }
        }
    }
    return s;
}