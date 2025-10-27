int num(int x){
	int res = 0;
	while (x){
		res += x % 10;
		x /= 10;
	}
	return res;
}
int check(int **t, int x, int y, int i, int j){
	if ((i > 0 && t[i - 1][j]) || (i < x - 1 && t[i + 1][j]) || (j > 0 && t[i][j - 1]) || (j < y - 1 && t[i][j + 1])){
		t[i][j] = 1;
		return 1;
	}
	return 0;
}
int movingCount(int m, int n, int k){
	int res = 1, **t = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++)
		t[i] = (int*)calloc(n, sizeof(int));
	t[0][0] = 1;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			int n = num(i) + num(j);
			if (n <= k && check(t, m, n, i, j))
				res++;
		}
	}
	return res;
}