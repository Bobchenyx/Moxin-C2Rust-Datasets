#define WORDSIZE 2000
#define WORDLEN 8

char g_tempWords[WORDSIZE][WORDLEN] = {0};
char g_Str[WORDSIZE * WORDLEN + WORDSIZE] = {0};
int g_tmpWordLen = 0;

int comp(const void *_a, const void *_b)
{
    return strlen((char *)_a) > strlen((char *)_b) ? -1 : 1;
}

int minimumLengthEncoding(char ** words, int wordsSize){

    g_tmpWordLen = 0;
    memset(g_Str, 0, sizeof(char) * (WORDSIZE * WORDLEN + WORDSIZE));
    memset(g_tempWords, 0, WORDSIZE * WORDLEN);

    for (int i = 0; i < wordsSize; i++) {
        memcpy(g_tempWords[i], words[i], strlen(words[i]));
        g_tmpWordLen++;
    }

    qsort(g_tempWords, g_tmpWordLen, sizeof(g_tempWords[0]), comp);
 
    for (int i = 0; i < g_tmpWordLen; i++) {
        char *subStr = strstr(g_Str, g_tempWords[i]);
        if (subStr == NULL) {
            strcpy(&g_Str[strlen(g_Str)], g_tempWords[i]);
            g_Str[strlen(g_Str)] = '#';
        } else {
            if (subStr[strlen(g_tempWords[i])] != '#') {
                strcpy(&g_Str[strlen(g_Str)], g_tempWords[i]);
                g_Str[strlen(g_Str)] = '#';
            }
        }
    }

    return strlen(g_Str);
}