/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **g_res;
int g_res_index;

void process(char *S, char *tmp, int index)
{
    index++;
    if (0 == strlen(S)) {
        g_res[g_res_index] = calloc(20, sizeof(char));
        //printf("tmp = %s\n", tmp);
        strcpy(g_res[g_res_index++], tmp);
        return;
    }
    for (int i = 0; i < strlen(S); i++) {
        tmp[index] = S[i];

        char *t = calloc(20, sizeof(char));
        memset(t, 0, 20);
        memcpy(t, S, i);
        memcpy(t + i, S + i + 1, strlen(S) - i - 1);
        //printf("tmp = %s, S = %s, t = %s, index = %d， i= %d\n", tmp, S, t, index, i);
        
        process(t, tmp, index);

        free(t);
    }
}

char** permutation(char* S, int* returnSize){
    g_res = calloc(9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 2, sizeof(char*));  //more input
    g_res_index = 0;

    char *tmp = calloc(20, sizeof(char));
    memset(tmp, 0, 20);

    process(S, tmp, -1);

    *returnSize = g_res_index;
    return g_res;
}