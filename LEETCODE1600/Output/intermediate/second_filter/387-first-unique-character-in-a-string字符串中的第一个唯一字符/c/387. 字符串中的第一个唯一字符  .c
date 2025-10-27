int firstUniqChar(char * s){
    int ht[128] = {0};
    int i=0;

    while (s[i] != '\0') {
            ht[s[i]]++;
            i++;
    }
    i = 0;
    while (s[i] != '\0') {
        if (ht[s[i]] == 1)
            return i;
        i++;
    }
    return -1;
}