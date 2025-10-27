#define MAX_CHAR 256
int Max(int a, int b)
{
    return a > b ? a : b;
}
int lengthOfLongestSubstring(char * s){
    
    int hash[MAX_CHAR] = {0};
    
    int maxLen = 0;
    int l = 0;
    for (int r = 0; r < strlen(s); r++) {
        
        hash[s[r]]++;
        while (l < r && hash[s[r]] > 1) {
            hash[s[l]]--;
            l++;
        }
        
        maxLen = Max(maxLen, r - l + 1);
        
    }
    return maxLen;

}