int max(int a, int b){
    return (a>b)?a:b;
}

int lengthOfLongestSubstring(char * s){
    int right = 0;
    int left = 0;
    int result = 0;

    while(s[right] != '\0'){
        for (int i = left; i < right; i++){
            if (s[right] == s[i]){
                left = i + 1;
            }
        }
        result = max(result, right-left+1);
        right++;
    }
    return result;
}