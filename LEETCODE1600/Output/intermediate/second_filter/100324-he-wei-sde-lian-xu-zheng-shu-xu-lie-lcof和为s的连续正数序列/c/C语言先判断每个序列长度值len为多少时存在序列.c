/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int i;
    int start, len;  //start：每个序列的第一个数；len：每个序列的长度
    int maxsize = sqrt(2*target);
    int** result = (int**)malloc(sizeof(int*)*maxsize);
    *returnColumnSizes = (int*)malloc(sizeof(int)*maxsize);

    *returnSize = 0;
    for(len=maxsize; len>1; len--){
        if(len%2==0 && target%len!=0 && (2*target)%len==0){  // 对除数为偶数情况，只有除得的结果为0.5,才存在
            result[*returnSize] = (int*)malloc(sizeof(int)*len);
            start = target/len - (len/2-1);
            for(i=0; i<len; i++){
                result[*returnSize][i] = start++;
            }
            (*returnColumnSizes)[*returnSize] = len;
            (*returnSize)++;
        }else if(len%2==1 && target%len==0){  // 对除数为奇数情况，只有能整除,才存在
            result[*returnSize] = (int*)malloc(sizeof(int)*len);
            start = target/len - len/2;
            for(i=0; i<len; i++){
                result[*returnSize][i] = start++;
            }
            (*returnColumnSizes)[*returnSize] = len;
            (*returnSize)++;
        }
    }
    return result;
}