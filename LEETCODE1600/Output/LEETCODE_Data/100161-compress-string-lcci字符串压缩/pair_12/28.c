#include <stdlib.h>

#define MAX_STR_LEN 50000

char* compressString(char* S) {
	if (S == NULL) {
		return S;
	}
	int len = strlen(S);
	if (len <= 0 || len > MAX_STR_LEN) {
		return S;
	}
	char* outS = (char*)malloc(sizeof(char) * (MAX_STR_LEN + 1));
	memset(outS, 0, sizeof(char) * (MAX_STR_LEN + 1));
	char countStr[6];
	int idx = 0;
	int count = 1;
	for (int i = 0; i < len; ++i) {
		if (i + 1 < len && S[i] == S[i + 1]) {
			count++;
		}
		else {
			outS[idx++] = S[i];
			snprintf(countStr, 6, "%d", count);
            strncpy(outS + idx, countStr, strlen(countStr) + 1);
            idx += strlen(countStr);
            if (idx >= len) {
		        return S;
	        }
			count = 1;
		}
	}
	if (idx >= len) {
		return S;
	}
	else {
		return outS;
	}
}