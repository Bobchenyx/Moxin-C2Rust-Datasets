#define MAX_SIZE (256)
int g_visit[MAX_SIZE];

bool canPermutePalindrome(char* s)
{
    int i;
    int len = strlen(s);
    int count = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        g_visit[i] = 0;
    }
    for (i = 0; i < len; i++) {
        g_visit[s[i]]++;
    }
    for (i = 0; i < MAX_SIZE; i++) {
        if (g_visit[i] % 2 != 0) {
            count++;
        }
    }
    if (count > 1) {
        return false;
    }
    return true;
}