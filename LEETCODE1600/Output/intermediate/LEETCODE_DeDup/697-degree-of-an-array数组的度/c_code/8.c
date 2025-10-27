#define MAX_LEN 50000

int g_index[MAX_LEN];
int g_grade[MAX_LEN];

int findShortestSubArray(int* nums, int numsSize){
	int i;
	int maxGrade = 0;
	int maxGradeLen = MAX_LEN;
	if (numsSize == 0 || nums == NULL) {
		return 0;
	}
	memset(g_grade, 0, sizeof(g_grade));
	for (i = 0; i < numsSize; i++) {
		g_grade[*(nums + i)]++;
		g_index[*(nums + i)] = i;
		if (maxGrade < g_grade[*(nums + i)]) {
			maxGrade = g_grade[*(nums + i)];
		}
	}

	for (i = 0; i < numsSize; i++) {
		if (g_grade[*(nums + i)] == maxGrade) {
			if (maxGradeLen > g_index[*(nums + i)] - i + 1) {
				maxGradeLen = g_index[*(nums + i)] - i + 1;
			}
		}
		g_grade[*(nums + i)] = 0;
	}

	return maxGradeLen;
}