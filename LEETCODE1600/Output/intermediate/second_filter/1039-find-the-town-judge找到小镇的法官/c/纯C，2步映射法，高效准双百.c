int findJudge(int N, int** trust, int trustSize, int* trustColSize){
	int i, res = 0;
	int *map = (int*)calloc(N + 2, sizeof(int));
	for (i = 0; i < trustSize; i++)
		map[trust[i][0]]++;
	for (i = 1; i <= N; i++)
		if (!map[i]){
			res = i;
            break;
        }
	if (!res)
		return -1;                              //至此，第一步结束
	memset(map, 0, sizeof(int)*(N + 2));
	for (i = 0; i < trustSize; i++)
		map[trust[i][1]]++;
	if (map[res] == N - 1)
		return res;
	return -1;
}