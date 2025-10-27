int longestPalindrome(char * s){
    if (!s) return 0;
    short cnt[52] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') cnt[s[i]-'a']++;
        if (s[i] >= 'A' && s[i] <= 'Z') cnt[s[i]-'A'+26]++;
    }

    int oddSel = 0;
    int ans = 0;
    for (int i = 0; i < 52; i++) {
        if (cnt[i] % 2 && oddSel != 1) {
            oddSel = 1;
            ans += cnt[i];
        } else if (cnt[i] % 2 && oddSel == 1) {
            ans += (cnt[i] - 1);
        } else {
            ans += cnt[i];
        }
    }
    return ans;
}