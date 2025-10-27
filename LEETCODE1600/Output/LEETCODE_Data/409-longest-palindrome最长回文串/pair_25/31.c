#define CHARACTERNUMS 26

int longestPalindrome(char * s){
    if (!s) {
        return 0;
    }
    int mapSize = 2 * CHARACTERNUMS;
    int mallocSize = sizeof(int) * mapSize;
    int* map = (int*)malloc(mallocSize);
    memset(map, 0, mallocSize);
    int sLen = strlen(s);
    for (int i = 0; i < sLen; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            map[s[i] - 'a']++;
        } else {
            map[CHARACTERNUMS + s[i] - 'A']++;
        }
    }
    bool hasEvenCharNum = false;
    int ret = 0;
    for (int i = 0; i < mapSize; i++) {
        if (map[i] & 0x1) {
            ret += map[i] - 1;
            if (!hasEvenCharNum) {
                hasEvenCharNum = true;
                ret++;
            }
        } else {
            ret += map[i];
        }
    }
    free(map);
    return ret;
}