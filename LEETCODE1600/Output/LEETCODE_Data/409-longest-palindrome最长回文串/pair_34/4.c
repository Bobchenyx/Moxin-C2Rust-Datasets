#define N 52
int longestPalindrome(char * s)
{
    if (s == NULL) {
        return NULL;
    }

    int len = strlen(s);
    int hash[N] = {0};

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            hash[s[i] - 'A']++;
        } else {
            hash[s[i] - 'a' + 26]++;
        }
        i++;
    }

    int maxLen = 0;
    int hasOdd= 0;
    int j;
    for (j = 0; j < N; j++) {
        if (hash[j] & 0x1 == 1) {
            hasOdd = 1;
            maxLen += hash[j] - 1;
        } else {
            maxLen += hash[j];
        }
    }

    maxLen += hasOdd;
    
    return maxLen;
}