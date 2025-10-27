/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    int min = pow(2, 2*n - 1);
    int max = pow(2, 2*n);
    char *tmp_str = malloc(2*n + 1);
    int left, dep;
    char **ret_str = (char **)malloc(sizeof(char *) * pow(2, 2 * n));
    *returnSize = 0;

    //printf ("min %d, max %d\n", min, max);

    int i, j;
    for (i = min; i < max; i++) {
        left = dep = 0;
        uint64_t tmp = i;
        memset(tmp_str, 0, 2*n + 1);
        for (j = 0; j < 2*n; j++) {
            if ((min & tmp) != 0) {
                left++;
                dep++;
                if (left > n) {
                    break;
                }
                tmp_str[j] = '(';
            } else {
                dep--;
                if (dep < 0) {
                    break;
                }
                tmp_str[j] = ')';
            }
            tmp = tmp << 1;
        }
        if (strlen(tmp_str) == 2 * n) {
            ret_str[*returnSize] = (char *)malloc(2 * n + 1);
            strncpy(ret_str[*returnSize], tmp_str, 2 * n + 1);
            (*returnSize)++;
        }
    }

    return ret_str;
}