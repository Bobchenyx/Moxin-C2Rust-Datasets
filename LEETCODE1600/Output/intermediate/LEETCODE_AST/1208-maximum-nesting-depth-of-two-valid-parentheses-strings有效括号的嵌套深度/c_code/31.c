/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int seqLen = strlen(seq);
    *returnSize = seqLen;
    int *result = (int *)calloc(seqLen, sizeof(int));
    int i = 0;
    for (; i < seqLen; ++i)
        result[i] = seq[i] == '(' ? (i & 1) : ((i + 1) & 1);
    return result;
}