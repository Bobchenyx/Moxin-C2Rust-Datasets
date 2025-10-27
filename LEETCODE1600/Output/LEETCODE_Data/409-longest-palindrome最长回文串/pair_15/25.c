int flags[52] = {0};
    int strLen = 0;
    for (; s[strLen] != '\0'; ++strLen) {
        int index = isupper(s[strLen]) ? s[strLen] -'A' + 26 : s[strLen] - 'a';
        flags[index]++;
    }