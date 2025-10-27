bool isOk(char *src, int hash[])
{
    int i = 0;
    while(src[i] != '\0') {
        if (hash[src[i] - 97] == 0) {
            return false;
        }
        else {
            hash[src[i] - 97]--;
        }
        i++;
    }
    return true; 
}

int countCharacters(char ** words, int wordsSize, char * chars){
    int sum = 0;
    int i = 0;
    int hash[26] = {0};
    int tmp[26] = {0};

    while(chars[i] != '\0') {
        hash[chars[i] - 97]++;
        i++;
    }

    for (i = 0; i < wordsSize; i++) {
        memcpy(tmp, hash, sizeof(int) * 26);
        if (isOk(words[i], tmp)) {
            sum += strlen(words[i]);
        }
    }

    return sum;
}