void merge(int* A, int ASize, int m, int* B, int BSize, int n) {
	int *tempA = malloc(sizeof(int) * m);
	memcpy(tempA, A, sizeof(int) * m);
	int idx = 0;
	for (int i = 0,j = 0; i < m || j < n;) {
		if (i >= m) {
			// A数组已经取完
			memcpy(A + idx, B + j, sizeof(int) * (n - j));
			break;
		}
		if (j >= n) {
			// B数组已经取完
			memcpy(A + idx, tempA + i, sizeof(int) * (m - i));
			break;
		}
		if (tempA[i] <= B[j]) {
			A[idx++] = tempA[i];
			i++;
		}
		else{
			A[idx++] = B[j];
			j++;
		}
	}
}