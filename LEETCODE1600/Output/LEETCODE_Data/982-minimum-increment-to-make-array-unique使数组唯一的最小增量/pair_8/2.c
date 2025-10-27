int CMP_INT(const void *_a,const void *_b) {
	return *(int*)_a - *(int*)_b;
}

int minIncrementForUnique(int* A, int ASize) {
	qsort(A, ASize, sizeof(int), CMP_INT);
	int count = 0;
	for (int i = 1; i < ASize; i++) {
		if (A[i] <= A[i - 1]) {
			count+=A[i-1]-A[i]+1;
			A[i] = A[i-1]+1;
		}
	}
	return count;
}