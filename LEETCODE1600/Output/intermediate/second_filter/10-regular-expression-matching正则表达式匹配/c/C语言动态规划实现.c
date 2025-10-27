bool isMatch(char * s, char * p){
    if (s == NULL || p == NULL) {
        return false;
    }

    if (p == NULL || strlen(p) == 0) {
        return strlen(s) == 0;
    }
    
    int len_s = strlen(s);
    int len_p = strlen(p);
    bool**f = (bool**)malloc((len_s + 1) * sizeof(bool*));
    for (int i = 0; i <= len_s; i++) {
        f[i] = (bool *)malloc(len_p + 1);
        memset(f[i], 0, len_p + 1);
    }
    
    f[0][0] = true;
    for (int j = 0; j < len_p; j++) {
        if (p[j] == '*') {
            f[0][j + 1] = f[0][j - 1];
        } else {
            f[0][j + 1] = false;
        }
    }

    for (int i = 0; i < len_s; i++) {
        for (int j = 0; j < len_p; j++) {
            if (p[j] == '*') {
                // 1.  x* 不存在
                if (j >= 1) {
                    f[i + 1][j + 1] = f[i + 1][j - 1];
                }
                // 2. x* 无需扩展x
                if (!f[i + 1][j + 1]) {
                    f[i + 1][j + 1] = f[i + 1][j];
                }                
                // 3. x* 需要扩展x
                if (!f[i + 1][j + 1] && (i >= 1)) {
                    if (s[i] == p[j - 1] || p[j - 1] == '.') {
                        f[i + 1][j + 1] = f[i][j + 1];
                    }
                }
            } else if ((p[j] == '.') || (s[i] == p[j])) {
                f[i + 1][j + 1] = f[i][j];
            }
        }
    }
    bool ret = f[len_s][len_p];
    for (int i = 0; i <= len_s; i++) {
        free(f[i]);
    }
    free(f);
    return ret;
}