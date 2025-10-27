/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    *returnSize = strlen(seq);
    int i, rn, n, *result = (int*)calloc(*returnSize, sizeof(int)), *hash = (int*)calloc((*returnSize) / 2, sizeof(int)); // hash存储第i个(所在位置
    for(i = 0, rn = 0;i < *returnSize;i ++){
        if(seq[i] == '('){
            hash[rn ++] = i;
            n = (n < rn ? rn : n);
        }
        else{
            if(rn > n / 2){
                result[i] = 1;
                result[hash[rn - 1]] = 1;
            }
            rn --;
        }
    }
    free(hash);
    return result;
}