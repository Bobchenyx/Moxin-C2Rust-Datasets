#define MAX 128

int longestPalindrome(char * s){
    int ans = 0;
    int len = strlen(s);
    int table[MAX];
    memset(table, 0, sizeof(int) * MAX);
    for (int i = 0; i < len; ++i) {
        table[(unsigned char)s[i]]++;
    }
    for (int i = 0; i < MAX; ++i) {
        if (table[i] != 0) {
            if (table[i] % 2 == 0) {
                ans += table[i];
            } else if (table[i] > 1) {
                ans += table[i] - 1;
            }
        }
    }
    return ans == len ? ans : ans + 1;
}