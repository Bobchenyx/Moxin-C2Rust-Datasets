int cmp(const void *a,const void *b)
{
    int *ap = *(int **)a;       
    int *bp = *(int **)b;

    if(ap[0] == bp[0])
        return ap[1] - bp[1];
    else
        return ap[0] - bp[0];
} 

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    int* dp = (int*)malloc(sizeof(int) * envelopesSize);
    int i, j;
    int max = 0;

    qsort(envelopes, envelopesSize, sizeof(envelopes[0]), cmp);

    for(i = 0; i < envelopesSize; i++) {
        dp[i] = 1;
    }

    for(i = 0; i < envelopesSize; i++) {
        for(j = 0; j < i; j++) {
            if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
    }

    for(i = 0; i < envelopesSize; i++) {
        max = fmax(max, dp[i]);
    }
    return max;
}