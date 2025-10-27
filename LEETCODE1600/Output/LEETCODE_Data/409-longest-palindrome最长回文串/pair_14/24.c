int longestPalindrome(char * s) {
	int count[2][26] = { 0 };
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if ('a' <= s[i]&&s[i] <= 'z') {
			count[0][s[i] - 97] ++;
		}else{
			count[1][s[i] - 65]++;
		}
	}
	int flag = 0;
	int ret = 0;
	for (int i = 0; i < 26; i++) {
		if (count[0][i] % 2 == 0) {
			ret += count[0][i];
		}
		else {
			flag = 1;
			ret += count[0][i] - 1;
		}
		if (count[1][i] % 2 == 0) {
			ret += count[1][i];
		}
		else {
			flag = 1;
			ret += count[1][i] - 1;
		}
	}
	return ret+flag;
}