int hasLeft(char *path, int *leftNum, int flagIndex)
{
    
    *leftNum = 0;
    int rightNum = 0;
    for (int i = 0; i < flagIndex; i++) {
        if(path[i] == '(') {
            (*leftNum)++;
        } else {
            rightNum++;
        }
    }
    return ((*leftNum) > rightNum);
}

void fillNext(char **res, char *path, int *returnSize, int n, int flagIndex)
{
    
    int pathLen = strlen(path);
    //printf("fill next:%d,%d,%d, %d,%s\n", (*returnSize), n, pathLen, flagIndex, path);
    
    if (flagIndex == (n * 2 - 1)) {
        path[flagIndex] = ')';
        int charSize = n * 2 + 1;
        char* newPath = (char *)malloc(sizeof(char) * (charSize));        
        memcpy(newPath, path, charSize);
        //printf("check new path:%s\n", newPath);
        //realloc(res, sizeof(char*) * ((*returnSize) + 2));
        res[(*returnSize)] = newPath;
        (*returnSize)++;
        return;
    }
    
    int leftNum = 0;
    if (hasLeft(path, &leftNum, flagIndex)) {        
        //printf("has left:%d,%d\n", leftNum, n);
        if (leftNum < n) {
            path[flagIndex] = '(';
            fillNext(res, path, returnSize, n, flagIndex + 1);
        }
        path[flagIndex] = ')';
        fillNext(res, path, returnSize, n, flagIndex + 1);
                
    } else {
        //printf("no left\n");
        path[flagIndex] = '(';
        fillNext(res, path, returnSize, n, flagIndex + 1);
    }
    
}

char ** generateParenthesis(int n, int* returnSize)
{
    *returnSize = 0;
    int maxSize = pow(2, n * 2);
    //printf("max size:%d\n", maxSize);
    char **res = (char **)malloc(sizeof(char *) * maxSize);
    memset(res, 0, sizeof(char*) * maxSize);
    if (n == 0) {
        (*returnSize)++;
        res[0] = "";
        return res;
    }
    if (n == 1) {
        (*returnSize)++;
        res[0] = "()";
        return res;
    }
    
    
    
    int charSize = n * 2 + 1;
    char *path = (char *)malloc(sizeof(char) * charSize);
    memset(path, 0, sizeof(char) * charSize);
    fillNext(res, path, returnSize, n, 0);
    
    return res;
}