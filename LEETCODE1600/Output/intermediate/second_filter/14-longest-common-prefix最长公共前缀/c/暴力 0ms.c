char * longestCommonPrefix(char ** strs, int strsSize){
	if (strsSize == 0) return "";
	if (strsSize == 1) return strs[0];
	
	int minSize = strlen(strs[0]);
	int i;
	int tmpLen;
	for (i = 1; i < strsSize; i++) {
		tmpLen = strlen(strs[0]);
		if (tmpLen < minSize) {
			minSize = tmpLen;
		}
	}
	if (minSize == 0) return "";
	char *res = malloc(minSize + 1);
	memset(res, 0, minSize + 1);
	int br = 0;
	for (i = 0; i < minSize; i++) {
		int j;
		for (j = 1; j < strsSize; j++) {
			if (strs[0][i] != strs[j][i]) {
				br = 1;
				break;
			}
		}
		if (br) {
			break;
		}
		res[i] = strs[0][i];
	}
	return res;
}