int countCharacters(char ** words, int wordsSize, char * chars){

    int ret = 0;

    int chrLength = strlen(chars);
    int* arr = (int*)malloc(sizeof(int) * 26);
    int* arrCpy = (int*)malloc(sizeof(int) * 26);
    memset(arr, 0, sizeof(int) * 26);
    memset(arrCpy, 0, sizeof(int) * 26);
    for (int i = 0; i < chrLength; i++) {
        arr[chars[i] - 'a']++;
        arrCpy[chars[i] - 'a']++;
    }
    for (int i = 0; i < wordsSize; i++) {
        bool flag = true;
        for (int j = 0; j < strlen(words[i]); j++) {
            if (arr[words[i][j] - 'a'] > 0) {
                arr[words[i][j] - 'a']--;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            ret += strlen(words[i]);
        }
        memcpy(arr, arrCpy, sizeof(int) * 26);
    }
    return ret;
}