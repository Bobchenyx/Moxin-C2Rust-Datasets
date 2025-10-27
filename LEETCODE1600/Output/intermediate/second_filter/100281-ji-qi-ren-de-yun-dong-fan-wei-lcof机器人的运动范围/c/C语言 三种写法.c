int isRightNum(int num1, int num2, int k){
	int tmp = 0;
	while (num1){
		tmp += num1 % 10;
		num1 /= 10;
	}
	while (num2){
		tmp += num2 % 10;
		num2 /= 10;
	}
	if (tmp <= k) return 1;
	return 0;
}

int movingCount(int m, int n, int k){
	if (k == 0) return 1;

	//m x n二维数组
	//动态规划
	int i, j, res = 0;
	int **arr = (int **)malloc(sizeof(int *)* m);
	for (i = 0; i < m; i++){
		arr[i] = (int *)calloc(n, sizeof(int));
	}
	arr[0][0] = 1;
	for (i = 0, j = 1; j < n; j++){ //第一行
		if (arr[i][j - 1] && isRightNum(i, j, k)) arr[i][j] = 1;
	}
	for (i = 1, j = 0; i < m; i++){ //第一列
		if (arr[i - 1][j] && isRightNum(i, j, k)) arr[i][j] = 1;
	}
	for (i = 1; i < m; i++){ //行
		for (j = 1; j < n; j++){ //列
			if (arr[i - 1][j] || arr[i][j - 1]) 
				if(isRightNum(i, j, k)) arr[i][j] = 1;
		}
	}
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			if (arr[i][j] == 1) {
				res++;
			}
				
		}
	}
	return res;
}