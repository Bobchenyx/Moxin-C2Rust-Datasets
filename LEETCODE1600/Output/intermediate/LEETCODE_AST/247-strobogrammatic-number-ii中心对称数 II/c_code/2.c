/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char mirrors[5] = {'0', '1', '6', '8', '9'};
char selfMirrors[3] = {'0', '1', '8'};

char getMirror(char num)
{
    switch(num) {
        case '0':
        case '1':
        case '8':
            return num;
        case '6':
            return '9';
        case '9':
            return '6';
        default:
            return 'X';
    }
}

void DFS(int n, char **ret, int *wi, char *stack, int sp, int halfLen, int hasMid)
{
    if (sp >= halfLen) {
        if (!hasMid) {
            memcpy(ret[(*wi)++], stack, n);
            return;
        }
        for (int i = 0; i < 3; i++) {
            stack[sp] = selfMirrors[i];
            memcpy(ret[(*wi)++], stack, n);
        }
        return;
    }
    for (int i = (sp == 0) ? 1 : 0; i < 5; i++) {
        stack[sp] = mirrors[i];
        stack[n - sp - 1] = getMirror(mirrors[i]);
        DFS(n, ret, wi, stack, sp+1, halfLen, hasMid);
    }
}

char ** findStrobogrammatic(int n, int* returnSize){
    int hasMid = (n % 2 == 1)? 1 : 0;
    int halfLen = n / 2;
    int totalNum = 1;
    if (n < 1)
        return NULL;
    for (int i = 0; i < halfLen; i++) {
        totalNum = (i == 0) ? 4 : totalNum * 5;
    }
    totalNum = (hasMid) ? totalNum * 3 : totalNum;
    printf("totalNum = %d\n", totalNum);
    char **ret = (char **)malloc(sizeof(char *) * totalNum);
    for (int i = 0; i < totalNum; i++) {
        ret[i] = (char *)malloc(sizeof(char) * (n+1));
        memset(ret[i], 0, sizeof(char) * (n + 1));
    }
    int wi = 0;
    int sp = 0;
    char *stack = (char *)malloc(sizeof(char) * (n+1));
    printf("start DFS...\n");
    DFS(n, ret, &wi, stack, sp, halfLen, hasMid);
    *returnSize = totalNum;
    return ret;
}