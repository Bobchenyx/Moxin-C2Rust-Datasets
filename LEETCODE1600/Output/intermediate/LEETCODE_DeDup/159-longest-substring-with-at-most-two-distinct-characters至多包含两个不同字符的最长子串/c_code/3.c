int lengthOfLongestSubstringTwoDistinct(char * s){
    int size = strlen(s);
    int max = 0;
    int left = 0;
    int right = 0;
    int cnt = 0;
    char first = '\0';
    char second = '\0';

    while (right < size) {
        while (s[right] == first || first == '\0') {
            first = s[right];
            right++;
        }

        while ((right < size) && (s[right] == second || second == '\0')) {
            second = s[right];
            right++;
        }

        while ((right < size) && (s[right] == first || s[right] == second)) {
            right++;
        }


        cnt = right - left;
        max = max > cnt ? max : cnt;

        left = right;
        first = s[left - 1];
        while ((second != '\0') && (first == s[left - 1])) {
            left--;
        }
        second = '\0';
        //printf("%d %d %d\n", left, right, max);
    }
    return max;
}