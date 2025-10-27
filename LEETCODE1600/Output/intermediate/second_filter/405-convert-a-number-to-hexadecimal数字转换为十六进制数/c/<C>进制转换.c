#define MAXS 64
char * toHex(int num) {
    unsigned int res, res2, m, n, i;
    char *result = NULL;
    unsigned int limit = 4294967296;
    result = (char *)malloc(sizeof(char) * MAXS);
    char letter[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    if (num < 0) {
        m = limit + num;
    } else {
        m = num;    
    }
    n = 16;
    i = 0;
    while (1) {
        res = m % n;
        res2 = m / n;
        m = res2;
        result[i++] = letter[res];
        if (res2 == 0) {
            break;
        }
    }
    int len = i / 2;
    char tmp;
    for (int j = 0; j < len; j++) {
        tmp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = tmp;
    }
    result[i] = '\0';
    return result;
}