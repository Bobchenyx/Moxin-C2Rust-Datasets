//解法一
int* getRow(int rowIndex, int* returnSize) {   
    rowIndex += 1;
    *returnSize = rowIndex;
    int** ret = (int**)malloc(sizeof(int) * (1 + rowIndex) * rowIndex / 2);
    for (int i = 0; i < rowIndex; i++) {
        ret[i] = (int*)malloc(sizeof(int) * (i + 1));
    }
    ret[0][0] = 1;
    for (int i = 1; i < rowIndex; i++) {
        ret[i][0] = 1;
        int j = 1;
        for (j = 1; j < i; j++) {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
        ret[i][j] = 1;
    }
    return ret[rowIndex - 1];
}

//解法二
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* pre = (int*)malloc(sizeof(int) * (rowIndex + 1));
    int* cur = (int*)malloc(sizeof(int) * (rowIndex + 1));
    pre[0] = 1;
    cur[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        cur[0] = 1;
        cur[i] = 1;
        for (int j = 1; j < i; j++) {
            cur[j] = pre[j] + pre[j - 1];
        }
        for (int k = 0; k <= i; k++) {
            pre[k] = cur[k];
        }
    }
    return cur;
}

//解法三
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* ret = (int*)malloc(sizeof(int) * (rowIndex + 1));
    int pre = 1;
    ret[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = 1; j < i; j++) {
            int tmp = ret[j];
            ret[j] += pre;
            pre = tmp;
        }
        ret[i] = 1;
    }
    return ret;
}

//解法四
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* ret = (int*)malloc(sizeof(int) * (rowIndex + 1));
    memset(ret, 0, sizeof(int) * (rowIndex + 1));
    ret[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j >= 1; j--) {
            ret[j] += ret[j - 1];
        }
    }
    return ret;
}