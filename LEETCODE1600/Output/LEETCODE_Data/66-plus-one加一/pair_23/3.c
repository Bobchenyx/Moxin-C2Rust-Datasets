int* plusOne(int* digits, int digitsSize, int* returnSize){
    int cnt = 0;
    int i;
    int retSize = 0;
    for (i = 0; i < digitsSize; i++) {
        if (digits[i] == 9) {
            cnt++;
        }
    }
    if (digitsSize == cnt) {
        retSize = digitsSize + 1;
    } else {
        retSize = digitsSize;
    }
    int *retArr = (int *)malloc(sizeof(int)*retSize);
    if(retSize == (digitsSize + 1)) {
        retArr[0] = 1;
        for (i = 1; i < retSize; i++) {
            retArr[i] = 0;
        }
    } else {
        if (digits[digitsSize - 1] != 9) {
            for (i = 0; i < retSize - 1; i++) {
                retArr[i] = digits[i];
        }
            retArr[retSize - 1] = digits[i] + 1;
        } else {
            int tmp = digitsSize - 1;
            while (digits[tmp] == 9) {
                retArr[tmp] = 0;
                tmp--;
            }
            retArr[tmp] = digits[tmp] + 1;
            for (i = 0; i < tmp; i++) {
                retArr[i] = digits[i];
            }
        }
    }

    *returnSize = retSize;
    return retArr;
}