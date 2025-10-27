int longestPalindrome(char * s)
{
    int *alpha = (int *)malloc(sizeof(int) * 58);
    memset(alpha, 0, sizeof(int) * 58);
    int sLen = strlen(s);
    int maxLen = 0;
    int oddNum = 0;

    for (int i = 0; i < sLen; i++) {
        alpha[s[i] - 'A']++;
    }

    for (int i = 0; i < 58; i++) {
        if (alpha[i] != 0) {
            if ((alpha[i] % 2) == 0) {
                maxLen += alpha[i];
                alpha[i] = 0; // 偶数个数的字符全部用完
            } else {
                oddNum++;
                if (alpha[i] > 1) {
                    maxLen += alpha[i] - 1;
                    alpha[i] = 1; // 奇数个数的字符用到只剩1个
                }
            }
        }
    }

    if (oddNum != 0) { // 若还有单个的字符串，则可以挑选一个来用
        maxLen++;
    }

    return maxLen;
}