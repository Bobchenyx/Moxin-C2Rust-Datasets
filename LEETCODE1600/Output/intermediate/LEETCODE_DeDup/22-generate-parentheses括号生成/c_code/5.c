/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int N;
int *res[2000];
int g_count;

void dfs(int l, int r, char *str){
    int len = strlen(str);

    if (l > N || r > N || r > l)
        return;

    if (l == N && r == N) {
            res[g_count] = malloc(N*2 + 1);
            memset(res[g_count], 0, N*2 + 1);
            strcpy(res[g_count++], str);
        return;
    }

    char temp[24] = {0};
    strcpy(temp, str);
    
    temp[len] = '(';
    temp[len + 1] = '\0';
    dfs(l+1, r, temp);
    
    temp[len] = ')';
    dfs(l, r+1, temp);
}

char ** generateParenthesis(int n, int* returnSize){
    char empty[4] = {0};
    N = n;
    g_count = 0;

    empty[0] = '(';
    dfs(1, 0, empty);

    //printf("g_count=%d\n", g_count);
    *returnSize = g_count;
    return res;
}