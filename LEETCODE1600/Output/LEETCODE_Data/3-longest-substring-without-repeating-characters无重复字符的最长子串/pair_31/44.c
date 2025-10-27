#define MAX_SIZE (128)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TRUE (1)
#define FALSE (0)

int g_visit[MAX_SIZE];

int lengthOfLongestSubstring(char * s)
{
    int i;
    int left;
    int right;
    int len = strlen(s);
    int maxLen = 1;    
    if (len == 0) {
        return 0;
    }
    for (i = 0; i < MAX_SIZE; i++) {
        g_visit[i] = FALSE;
    }
    left = right = 0;
    g_visit[s[right]] = TRUE;
    while (1) {
        right++;
        if (right >= len) {
            break;
        }        
        if (g_visit[s[right]] == TRUE) {
            while (s[left] != s[right]) {
                g_visit[s[left]] = FALSE;
                left++;
            }
            left++;            
        } else {
            g_visit[s[right]] = TRUE;
        }
        maxLen = MAX(maxLen, right - left + 1);        
    }
    return maxLen;
}