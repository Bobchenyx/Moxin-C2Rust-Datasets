//将字符串存入哈希表
void mapCharacter(char* chars, char* characterMap) {
    memset(characterMap, 0, sizeof(char) * 26);
    for(int i = 0; chars[i] != '\0'; i ++) {
        characterMap[chars[i] - 'a'] ++;
    }
}

int countCharacters(char ** words, int wordsSize, char * chars){
    char characterMap[26] = {0};
    int count = 0;
    for(int i = 0, j = 0; i < wordsSize; i ++) {
        mapCharacter(chars, characterMap);
        j = 0;
        for(; words[i][j] != '\0'; j ++) {
            if(characterMap[words[i][j] - 'a'] == 0) {
                j = 0;
                break;
            }
            characterMap[words[i][j] - 'a'] --;
        }
        count += j;
    }
    return count;
}