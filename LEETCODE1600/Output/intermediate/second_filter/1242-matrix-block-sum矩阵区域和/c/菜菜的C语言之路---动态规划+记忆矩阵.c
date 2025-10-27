#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
// 输入m、n, 创建对应的二维矩阵并初始化为零值后输出;
int** createMatrix(int m, int n) {
	int**a = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	return a;
}
// 返回两数最大值
int compareMax(int a, int b) {
	return a > b ? a : b;
}
// 返回两数最小值
int compareMin(int a, int b) {
	return a > b ? b : a;
}
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int K, int* returnSize, int** returnColumnSizes) {
	int m = matSize, n = *matColSize;
	if (m == 0 || n == 0) {
		return NULL;
	}
	// 确定行、列号
	*returnSize = matSize;
	*returnColumnSizes = matColSize;
	int**memo = createMatrix(m, n);
	// 创建记忆矩阵memo
	for (int i = 0; i < m;i++) {
		for (int j = 0; j < n;j++) {
			memo[i][j] = mat[i][j];
			if (i > 0) {
				memo[i][j] += memo[i - 1][j];
			}
			if (j > 0) {
				memo[i][j] += memo[i][j - 1];
			}
			if (i > 0 && j > 0) {
				memo[i][j] -= memo[i - 1][j - 1];
			}
		}
	}
	// 创建结果矩阵res
	int**res = createMatrix(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int r1 = compareMax(i - K, 0), r2 = compareMin(i + K, m - 1);
			int c1 = compareMax(j - K, 0), c2 = compareMin(j + K, n - 1);
			res[i][j] = memo[r2][c2];
			if (r1 > 0) {
				res[i][j] -= memo[r1 - 1][c2];
			}
			if (c1 > 0) {
				res[i][j] -= memo[r2][c1 - 1];
			}
			if (r1 > 0 && c1 > 0) {
				res[i][j] += memo[r1 - 1][c1 - 1];
			}
		}
	}
	return res;
}