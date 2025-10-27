/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* ret = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int len = digitsSize + 1;
    int i = digitsSize;
    int c = 1;

    while(len > 1 || c == 1) {
        if(i>0) c = digits[--i] + c;
        ret[--len] = c == 10 ? 0 : c;
        c = c == 10 ? 1 : 0;
    }
    *returnSize = digitsSize + 1 - len;

    return ret + len;
}