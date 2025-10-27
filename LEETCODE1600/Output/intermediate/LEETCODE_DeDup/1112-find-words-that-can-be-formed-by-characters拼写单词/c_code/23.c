#define HASH_SIZE (26)
#define GET_HASH_SUB(val) ((val) % HASH_SIZE)

int countCharacters(char ** words, int wordsSize, char * chars){
    int hash[HASH_SIZE];
    int tmpHash[HASH_SIZE];
    int len = 0;
    char *pChar = chars;
    int retLen = 0;
    int sub = 0;

    if(NULL == words
        || 0 == wordsSize
        || NULL == chars
        || 0 == strlen(chars)){
        return 0;
    }

    memset(hash, 0, sizeof(hash));
    while(*pChar != '\0'){
        hash[GET_HASH_SUB(*pChar)]++;
        pChar++;
    }

    for(int i = 0; i < wordsSize; i++){
        memcpy(tmpHash, hash, sizeof(hash));
        pChar = words[i];
        len = 0;
        while(*pChar != '\0'){
            sub = GET_HASH_SUB(*pChar);
            if(0 == tmpHash[sub]){
                break;
            }
            tmpHash[sub]--;
            pChar++;
            len++;
        }
        if(*pChar == '\0'){
            retLen += len;
        }
    }
    
    return retLen;
}