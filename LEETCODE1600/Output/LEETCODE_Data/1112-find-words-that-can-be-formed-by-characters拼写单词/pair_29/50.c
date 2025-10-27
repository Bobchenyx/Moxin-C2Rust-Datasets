int countCharacters(char ** words, int wordsSize, char * chars){
    if (!words || wordsSize == 0 || !chars) return 0;

    int ans = 0;
    int cmap[26] = {0};
    for (int i = 0; i < strlen(chars); i++) {
        cmap[chars[i] - 'a'] ++;
    }

    for (int i = 0; i < wordsSize; i++) {
        int tmp[26];
        int j;
        memcpy(tmp, cmap, sizeof(cmap));
        for (j = 0; j < strlen(words[i]); j++) {
            if (tmp[words[i][j] - 'a'] == 0) break;
            tmp[words[i][j] - 'a']--;
        }
        if (j >= strlen(words[i])) ans += strlen(words[i]);
    }
    return ans;
}