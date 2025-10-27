int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int *dp = malloc((N + 1)* sizeof(int));
    int i = 0;

    memset(dp, 0 , (N + 1) * sizeof(int));
    for (i = 0; i < trustSize; i++) {
        dp[trust[i][0]]--;
        dp[trust[i][1]]++;
    }

    for (i = 1; i <= N; i++) {
        if (dp[i] == N -1)
            return i;
    }

    return -1;
}