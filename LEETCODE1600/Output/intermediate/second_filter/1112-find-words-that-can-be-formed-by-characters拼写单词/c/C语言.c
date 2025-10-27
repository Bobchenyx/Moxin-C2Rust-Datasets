int countCharacters(char ** words, int wordsSize, char * chars){
    int charNum[128]     = {0};
    int tempCharNum[128] = {0};
    int length           = 0;
    int wordLength       = 0;
    int i                = 0;
    int j                = 0;

    for (i = 0; chars[i] != '\0'; i++) {
        charNum[chars[i]] ++;
    }

    for (i = 0; i < wordsSize; i++) {
        wordLength = 0;
        memcpy(tempCharNum, charNum, sizeof(int) * 128);
        for (j = 0; words[i][j] != '\0'; j++) {
            if (tempCharNum[words[i][j]] > 0) {
                wordLength ++;
                tempCharNum[words[i][j]]--;
            } else {
                wordLength = 0;
                break;
            }
        }
        length += wordLength;
    }

    return length;
}