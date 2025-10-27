char g_tos[50000] = {0};
int  g_ti = -1;

int  g_sb[5000] = {0};
int  g_sc[5000] = {0};
int  g_tb = -1;
int  g_tc = -1;

char * decodeString(char * s){
    g_ti = -1;
    g_tb = -1;
    g_tc = -1;
    int len = strlen(s);
    int tk = 0;
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            tk = tk * 10 + (s[i] - '0');
            continue;
        }
        k = tk;
        tk = 0;
        if (s[i] == '[') {
            g_sb[++g_tb] = k;
            g_sc[++g_tc] = g_ti;
            continue;
        }
        if (s[i] == ']') {
            int kk = g_sb[g_tb--];
            int ts = g_sc[g_tc--];
            int te = g_ti;
            for (int ki = 1; ki < kk; ki++) {
                for (int iii = 0; iii < te - ts; iii++) {
                    g_tos[++g_ti] = g_tos[ts + iii + 1];
                }
            }
            g_ti = ts + (te - ts) * kk;
            continue;
        }
        g_tos[++g_ti] = s[i];
    }
    g_tos[g_ti + 1] = 0;
    return g_tos;
}