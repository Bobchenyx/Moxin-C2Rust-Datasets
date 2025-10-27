int maxLength;
int maxIndex;
void longest(char *s, int size) {
    for(int i = 0; i < size; i++) {
        if(s[i] == s[size - 1]) {
            int left = i + 1;
            int right = size - 2;
            while(left < right) {
                if(s[left] != s[right]) {
                    break;
                }
                left++;
                right--;
            }
            if(left >= right) {
                if(maxLength < size - i) {
                    maxLength = size -i;
                    maxIndex = i;
                }
            }
        }
    }
}
char * longestPalindrome(char * s){
    maxIndex = 0;
    maxLength = 0;
    if(strlen(s) < 2) {
        return s;
    }
    for(int i = strlen(s); i >= 2; i--) {//size 从最大取到2 ，解肯定在里面，找个最大就可以了
        if(i > maxLength)//如果size 已经小于maxlength了，说明解肯定已经找到了
            longest(s, i);
    }
    char *retStr = malloc(maxLength + 1);
    memset(retStr, '\0', maxLength + 1);
    strncpy(retStr, s + maxIndex, maxLength);
    return retStr;
}