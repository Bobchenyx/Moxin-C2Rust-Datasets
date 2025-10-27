#include<string.h>

void sortWords(char** words, int wordsSize) {
    int count = 0;
    char* temp;
    for (int i = 1; i < 7; ++i) {
        for (int j = 0; j < wordsSize; ++j) {
            if (strlen(*(words + j)) == i) {
                temp = *(words + count);
                *(words + count) = *(words + j);
                *(words + j) = temp;
                count++;
                if (count >= wordsSize) return;
            }
        }
    }
}

int minimumLengthEncoding(char ** words, int wordsSize){
    int* wordsLen = (int*)malloc(sizeof(int) * wordsSize);
    int minLen = 0;

    sortWords(words, wordsSize);
    for (int i = 0; i < wordsSize; ++i) {
        *(wordsLen + i) = strlen(*(words + i));
        minLen += *(wordsLen + i);
    }
    minLen += wordsSize;
    for (int i = 0; i < wordsSize - 1; ++i) {
        for (int j = i + 1; j < wordsSize; ++j) {
            if (strcmp(words[i], words[j] + (*(wordsLen + j) - *(wordsLen + i))) == 0) {
                minLen -= *(wordsLen + i) + 1;
                break;
            }
        }
    }
    return minLen;
}