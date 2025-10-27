int* maxDepthAfterSplit(char * seq, int* returnSize)
{
    int slen = strlen(seq);
    int cnt = 0;
    *returnSize = slen;
    int *result = (int *)malloc(sizeof(int) * slen);
    for (int i = 0; i < slen; i++) {
        if (seq[i] == '(') {
            result[i] = cnt % 2;
            cnt++;
        } else {
            cnt--;
            result[i] = cnt % 2;
        }
    }
    return result;
}