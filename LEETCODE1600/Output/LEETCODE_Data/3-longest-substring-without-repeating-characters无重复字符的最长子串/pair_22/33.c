#define max(a,b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char * s) {
    int Idx[128] = { 0 };
    int ret = 0;

    for (int i = 1, left = 1; *s; s++, i++) {
        if (Idx[*s] < left) {
            ret = max(ret, (i - left + 1));
        } else {
            left = Idx[*s] + 1;
        }
         Idx[*s] = i;
    }
    return ret;
}