char findTheDifference(char * s, char * t){
    int* hash1 = (int*)malloc(sizeof(int) * 26);
    int* hash2 = (int*)malloc(sizeof(int) * 26);
    memset(hash1, 0, sizeof(int) * 26);
    memset(hash2, 0, sizeof(int) * 26);
    int len1, len2, i;

    len1 = strlen(s);
    len2 = strlen(t);

    for(i = 0; i < len1; i++) {
        hash1[s[i] - 'a']++;
    }
    for(i = 0; i < len2; i++) {
        hash2[t[i] - 'a']++;
    }
    for(i = 0; i < 26; i++) {
        if(hash1[i] + 1 == hash2[i]) {
            break;
        }
    }
    return 'a' + i;
}