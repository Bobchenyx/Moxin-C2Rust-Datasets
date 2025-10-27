/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *num = (int*)malloc((digitsSize + 1) * sizeof(int));
    num[0] = 1;
    *returnSize = digitsSize;
    for(int i = digitsSize - 1; i >= 0; i--){
        if(digits[i] == 9){
            digits[i] = 0;
        }
        else{
            digits[i]++;
            break;
        }
    }
    if(digits[0] == 0){
        for(int i = 0; i < digitsSize; i++){
            num[i + 1] = digits[i];
        }
        * returnSize = digitsSize + 1;
        return num;
    }
    else
        return digits;
}