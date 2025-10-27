int a[27];
int firstUniqChar(char * s){
    memset(a, 0, sizeof(a));
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        a[s[i] - 'a']++;
    for (int i = 0; i < len; i++) {
        if (a[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}