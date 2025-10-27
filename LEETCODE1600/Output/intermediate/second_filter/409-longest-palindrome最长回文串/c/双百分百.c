#include <string.h>

int longestPalindrome(char * s){
    int i, cnt[60] = {0}, ans = 0, flag = 0;
    int len = strlen(s);
    for (i = 0; i < len; i++) {
        cnt[s[i] - 'A']++;
    }
    for (i = 0; i < 60; i++) {
        if (cnt[i] != 0) {
            if (cnt[i] % 2) {//奇数
                flag = 1;
                ans += (cnt[i] - 1);
            } else {
                ans += cnt[i];
            }
        }
    }
    if (flag)  return (ans + 1);
    return ans;
}