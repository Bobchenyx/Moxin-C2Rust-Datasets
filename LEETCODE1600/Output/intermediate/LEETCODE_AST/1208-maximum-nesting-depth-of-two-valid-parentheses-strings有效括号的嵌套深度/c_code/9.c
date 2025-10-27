/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getHalfDepth(char *seq) {
    char *tmp = seq;
    int top = 0;
    int depmax = 0;
    while (*tmp != '\0') {
        if (*tmp == '(') {
            top++;
            if (depmax < top)
                depmax = top;
        } else {
            top--;
        }
        tmp++;
    }

    return depmax / 2;
}

void setRet(int top, int dep, int idx, int *ret) {
    if (top < dep) 
        ret[idx] = 0;
    else
        ret[idx] = 1;
}

int* maxDepthAfterSplit(char * seq, int* returnSize){
    *returnSize = strlen(seq);
    int *ret = (int *)malloc(sizeof(int) * strlen(seq));
    memset(ret, 0, sizeof(int) * strlen(seq));

    int top = 0;
    int dep = 0;
    int idx = 0;
    char *tmp = seq;

    dep = getHalfDepth(seq);

    while (*tmp != '\0') {
        if (*tmp == '(') {
            setRet(top, dep, idx, ret);
            top++;
        } else {
            top--;
            setRet(top, dep, idx, ret);
        }
        tmp++;
        idx++;
    }

    return ret;
}