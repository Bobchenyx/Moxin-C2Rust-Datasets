char *s = malloc(sizeof(char) * n * 2 +1);
    *returnSize = 0; //默认是0
    int initSize = comb(n);
    char **ret = malloc(sizeof(char*) * initSize);