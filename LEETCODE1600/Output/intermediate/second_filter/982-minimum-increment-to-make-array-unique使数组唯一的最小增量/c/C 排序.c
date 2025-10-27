int cmp(const void *a, const void *b) {
	return *(int*)a > *(int*)b;
}
int minIncrementForUnique(int* A, int ASize) {
	if (A == NULL || ASize <= 1) return 0;
	int move = 0;
	int prev = 0;
	// sort
	qsort(A, ASize, sizeof(int), cmp);
	for (int i = 1; i < ASize; ++i) {
		if (A[i] <= A[i - 1]) {
			prev = A[i];
			A[i] = A[i - 1] + 1;
			move += A[i] - prev;
		}
	}
	return move;
}