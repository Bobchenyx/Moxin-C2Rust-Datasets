/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int searchend(char *s, int len, int start, int *ht){
    int i = 0;
    
    ht[s[start]] = start;
    for (i = len -1; i >=start; i--) {
        if (ht[s[i]] == start) {
            ht[s[i]] = i;
            break;
        }
    }

    return i;
}

int* partitionLabels(char * S, int* returnSize){
    int ht[128] = {0};
    int i = 0, j = 0, end = 0, start = 0, max=0;
    int len = strlen(S);
    int *res = malloc(len*sizeof(int));

#if 0
    for (i = 0; i < 128; i++)
        ht[i] = -1;

    max = searchend(S, len, 0, ht);
    for (i = 1; i < len; i++) {
        if (ht[S[i]] == -1) {
            if (i < max) {
                end = searchend(S, len, i, ht);
                max = max > end ? max : end;
            }else{
                end = i - 1;
                res[j++] = end - start + 1;
                start = i;
                max = searchend(S, len, i, ht);
            }
        }
    }
    res[j++] = len - start;
#else
    for (i =0 ; i < len; i++)
        ht[S[i]] = i;

    for (i = 0; i < len; i++) {
        end = end > ht[S[i]] ? end : ht[S[i]];
        if (i == end) {
            res[j++] = end - start + 1;
            start = i + 1;
        }
    }

#endif 

    *returnSize = j;
    return res;
}