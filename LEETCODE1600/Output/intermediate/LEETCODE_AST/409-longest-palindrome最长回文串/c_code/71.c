#include <stdlib.h>
#include <assert.h>
#include <string.h>

int longestPalindrome(char * s) {
	if (s == NULL) {
		return 0;
	}
	int alphaA[26] = { 0 };
	memset(alphaA, 0, sizeof(int) * 26);
	int alphaB[26] = { 0 };
	memset(alphaB, 0, sizeof(int) * 26);

	int odd = 0;
	for (int i = 0; i < strlen(s); ++i) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			alphaA[s[i] - 'a']++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			alphaB[s[i] - 'A']++;
		}
		else {
			// do nothing
		}
	}

	for (int i = 0; i < 26; ++i) {
		if (alphaA[i] != 0) {
			if (alphaA[i] % 2 != 0) {
				odd += 1;
			}
		}
		if (alphaB[i] != 0) {
			if (alphaB[i] % 2 != 0) {
				odd += 1;
			}
		}
	}
	return odd == 0 ? strlen(s) : strlen(s) - odd + 1;
}