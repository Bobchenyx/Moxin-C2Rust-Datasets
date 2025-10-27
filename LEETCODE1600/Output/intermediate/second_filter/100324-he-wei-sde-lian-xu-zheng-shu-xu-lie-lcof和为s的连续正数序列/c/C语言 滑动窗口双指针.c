int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes) {
	if (target == 0) {
		*returnSize = 0;
		**returnColumnSizes = 0;
		return 0;
	}

	int midNum = target / 2 + 1;
	int idx = 0;
	int **rtnSeq = (int**)malloc(sizeof(int*) * target);
	int* col = (int*)malloc(sizeof(int) * target);

	for (int i = 1, j = 1; i <= target / 2 + 1;) {
		if ((i + j) * (j - i + 1) / 2 > target) {
			i++;
		}
		else if ((i + j) * (j - i + 1) / 2 < target) {
			j++;
		}
		else {
			// record
            int len = j - i + 1;
			rtnSeq[idx] = (int*)malloc(sizeof(int) * len);
			for (int k = 0; k < len; k++) {
				rtnSeq[idx][k] = i + k;
			}
			col[idx] = len;
			idx++;
			i++;
		}
	}
	*returnColumnSizes = col;
	*returnSize = idx;
	return rtnSeq;
}