/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len = strlen(seq);
	*returnSize = len;
	int *res = (int*)malloc(sizeof(int) * len);
	// 模拟派分 A序列对应a-0,B序列对应b-1   '(' +1, ')' -1
	int a = 0;
	int b = 0;
	for (int i = 0; i < len; i++) {
		if (seq[i] == '(') {
			// 按优先级排序
			if (a == 0) {
				a++;
				res[i] = 0;
			} else if (b == 0) {
				b++;
				res[i] = 1;
			} else if (a < b) {
				a++;
				res[i] = 0;
			} else if (a >= b) {
				b++;
				res[i] = 1;
			}
		} else {
			if (a > b) {
				a--;
				res[i] = 0;
			} else {
				b--;
				res[i] = 1;
			}
		}
	}
	return res;
}