#define MAX 128
int countCharacters(char ** words, int wordsSize, char * chars){
    if (words == NULL || wordsSize == 0 || chars == NULL) {
        return 0;
    }

    int dictSize = strlen(chars);
    int *dict = (int *)malloc(sizeof(int) * MAX);
    memset(dict, 0, MAX);
    for (int i = 0; i < dictSize; i++) {
        dict[(int)chars[i]]++;
    }

    int res = 0;
    for (int k = 0; k < wordsSize; k++) {
        int wordLength = strlen(words[k]);
        int flag = 1;
        int *wordDict = (int *)malloc(sizeof(int) * MAX);
        memset(dict, 0 , MAX);
        for (int j = 0; j < wordLength; j++) {
            wordDict[(int)words[k][j]]++;
            if (wordDict[(int)words[k][j]] > dict[(int)words[k][j]]) {
                flag = 0;
                break;
            }
        }
        free(wordDict);
        if (flag == 1) {
            res += wordLength;
        }
    }

    free(dict);
    return res;
}