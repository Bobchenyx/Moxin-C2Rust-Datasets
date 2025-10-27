#define SIZE 20005
char cash[SIZE];

int Cmp(const void* a, const void* b)
{
    char* aa = *(char**)a;
    char* bb = *(char**)b;
    return strlen(bb) - strlen(aa);
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if (words == NULL || wordsSize == 0) {
        return 0;
    }
    qsort(words, wordsSize, sizeof(char*), Cmp);
    memset(cash, 0, sizeof(cash));
    strcpy(cash, words[0]);
    strcat(cash, "#");
    int i;
    char* findStr = NULL;
    for (i = 1; i < wordsSize; ++i) {
        findStr = strstr(cash, words[i]);
        if (!findStr || *(findStr + strlen(words[i])) != '#') {
            strcat(cash, words[i]);
            strcat(cash, "#");
        }

    }
    return strlen(cash);
}