/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 1;
    int i;
    for (i = digitsSize - 1; i >= 0; i--) {
        int sum;
        sum =digits[i] + carry;
        carry = sum / 10;
        digits[i] = sum % 10;
    }
    if (carry) {
        *returnSize = digitsSize + 1;
        int *ret = (int*)malloc(sizeof(int) * (*returnSize));
        int j = 0;
        int k = 1;
        ret[0] = 1;
        for (; j < digitsSize; j++, k++) {
            ret[k] = digits[j];
        }
        return ret;
    }
    *returnSize = digitsSize;
    return digits;
}