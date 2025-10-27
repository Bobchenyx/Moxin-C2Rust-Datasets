/**
 * Note: The returned array must be malloced, assume caller calls free()
 */

int dig_len;
int g_count;
char *res[2000];


int dig2letters(char * letters, char digi) {
    int i = 0;

    if(digi >= '2' && digi <= '6') {
        letters[0] = (digi - 50)*3 + 'a';
        letters[1] = (digi - 50)*3 + 1 + 'a' ;
        letters[2] = (digi - 50)*3 + 2 + 'a';
        return 3;
    }
    switch (digi) {
        case '7':
            letters[0] = 'p';
            letters[1] = 'q';
            letters[2] = 'r';
            letters[3] = 's';
            return 4;
        case '8':
            letters[0] = 't';
            letters[1] = 'u';
            letters[2] = 'v';
            return 3;
        case '9':
            letters[0] = 'w';
            letters[1] = 'x';
            letters[2] = 'y';
            letters[3] = 'z';
            return 4;
        default:
            return 0;
    }
}


void dfs (char * digits, int index, char * str) {
    int len = strlen(str);
    
    if (index == dig_len) {
        res[g_count] = malloc(len + 1);
        memset(res[g_count], 0, len + 1);
        strcpy(res[g_count++], str);
        return;
    }

    char temp[16] = {0};
    char letters[4];
    int i = 0, count;

    strcpy(temp, str);
    count = dig2letters(letters, digits[index]);

    for (i = 0; i < count; i++) {
        temp[len] = letters[i];
        temp[len + 1] = '\0';
        dfs(digits, index + 1, temp);
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    char empty[4] = {0};

    g_count = 0;
    dig_len = strlen(digits);
    
    if (dig_len == 0) {
        *returnSize = 0;
        return NULL;
    }

    dfs(digits, 0, empty);

    *returnSize = g_count;
    return res;
}