#define PRINTF //printf

bool isMatch(char *s, char *p)
{
    int s_len = strlen(s);
    int p_len = strlen(p);
    int i_loop, j_loop, temp_i, i, j;
    char **dp;

    if ((p_len == 2) && (p[0] == '.') && (p[1] == '*')) {
        return true;
    }

    if (p_len == 0) {
        if (s_len == 0) {
            return true;
        } else {
            return false;
        }
    }

    dp = (char **)malloc(sizeof(char **) * (p_len + 1));
    if (dp == NULL) {
        return false;
    } else {
        for (j_loop = 0; j_loop < p_len + 1; j_loop++) {
            dp[j_loop] = (char *)malloc(sizeof(char) * (s_len + 1));
            if (dp[j_loop] == NULL) {
                return false;
            } else {
                memset(dp[j_loop], false, s_len + 1);
            }
        }
    }

    dp[0][0] = true;
        for (j_loop = 1; j_loop < p_len + 1; j_loop++) {
        if (p[j_loop - 1] == '*') {
            PRINTF("\n[%3d]dp[j_loop - 2][0]=%d", __LINE__, dp[j_loop - 2][0]);
            dp[j_loop][0] = dp[j_loop - 2][0];
        }
    }

    PRINTF("\n[%3d]init dp:", __LINE__);
    PRINTF("\n[%3d]    # ", __LINE__);
    for (i_loop = 0; i_loop < s_len ; i_loop++) {
        PRINTF(" %c ", s[i_loop]);
    }

    for (j_loop = 0; j_loop < p_len + 1; j_loop++) {
        if (j_loop == 0) {
            PRINTF("\n[%3d] # ", __LINE__);
        } else {
            PRINTF("\n[%3d] %c ", __LINE__, p[j_loop - 1]);
        }

        for (i_loop = 0; i_loop < s_len + 1; i_loop++) {
            PRINTF(" %d ", dp[j_loop][i_loop]);
        }
    }

    for (i_loop = 1; i_loop < s_len + 1; i_loop++) {
        for (j_loop = 1; j_loop < p_len + 1; j_loop++) {
            i = i_loop - 1;
            j = j_loop - 1;
            PRINTF("\n[%3d]p[%d]=%c, s[%d]=%c", __LINE__, j, p[j], i, s[i]);
            if (p[j] == s[i]) {
                dp[j_loop][i_loop] = dp[j_loop - 1][i_loop - 1];
            } else {
                if (p[j] == '*') {
                    if (p[j - 1] == '.') {
                        // .*
                        if (j_loop == 2) {
                            // 在patern开头的情况
                            dp[j_loop][i_loop] = true;
                        } else {
                            // 不在开头
                            for (temp_i = 0; temp_i < s_len + 1; temp_i++) {
                                if (dp[j_loop - 2][temp_i]) {
                                    dp[j_loop][i_loop] = true;
                                    break;
                                }
                            }                       
                        }
                    } else {
                        PRINTF("\n[%3d]p[j-1]=%c, s[i]=%c, s[i-1]=%c", __LINE__, p[j - 1], s[i], s[i - 1]);

                        // 0 * p[j-1]
                        if (dp[j_loop - 2][i_loop] == true) {
                            dp[j_loop][i_loop] = true;
                            continue;
                        }

                        // 1 * p[j-1]
                        if ((p[j - 1] == s[i]) && (dp[j_loop][i_loop - 1] == true)) {
                            dp[j_loop][i_loop] = true;
                            continue;
                        }
                    }
                } else if (p[j] == '.') {
                    dp[j_loop][i_loop] = dp[j_loop - 1][i_loop - 1];
                }
            }
        }
    }

    PRINTF("\n[%3d]after calculated dp:", __LINE__);
    PRINTF("\n[%3d]    # ", __LINE__);
    for (i = 0; i < s_len ; i++) {
        PRINTF(" %c ", s[i]);
    }

    for (j = 0; j < p_len + 1; j++) {
        if (j == 0) {
            PRINTF("\n[%3d] # ", __LINE__);
        } else {
            PRINTF("\n[%3d] %c ", __LINE__, p[j - 1]);
        }

        for (i = 0; i < s_len + 1; i++) {
            PRINTF(" %d ", dp[j][i]);
        }
    }

    return dp[p_len][s_len];
}