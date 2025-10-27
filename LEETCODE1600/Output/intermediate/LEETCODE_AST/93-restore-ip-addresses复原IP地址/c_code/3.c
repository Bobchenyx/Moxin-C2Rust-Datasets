/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int g_count = 0;
char* g_ipAdrs[50];
char  g_ipaddr[16] = "\0";
void StrIpAddr(void) {
    char *ipaddr = NULL;
    ipaddr = (char*)malloc(16 * sizeof(char));
    memset(ipaddr, 0, sizeof(ipaddr));
    strcpy(ipaddr, g_ipaddr);
    printf("num: %d, IP=%s \n",g_count,ipaddr);
    g_ipAdrs[g_count] = ipaddr;
    g_count++;
    return;
}
// pos：当前迭代开始的位置 step:已经执行了part
// pos：当前迭代开始的位置 step:已经执行了part
void dfs(char * s, int pos, int step) {
    int num = 0;
    int i;
    int count = 1;
    char *ipaddr = NULL;

    if (pos >= strlen(s)) {
        return;
    }

    // 停止条件
    if (step == 3) {
        if ((strlen(s) - pos > 3) || 
            ((pos != strlen(s) - 1) && (s[pos] == '0'))) {
            return;
        }
        for (i=strlen(s) - 1; i >= pos; i--) {
            num = num + (s[i] - '0') * count;
			count *= 10;
        }
        if (num <= 255) {
            strncat(g_ipaddr, s + pos, strlen(s) - pos);
            StrIpAddr(); // 四个部分都满足时，存储这个IP地址串
            return;
        }
        return;
    }

    // 使用一位数,大于0时随便用，等于0时不能尝试两位和三位
    if ((s[pos] - '0') > 0) {
        strncat(g_ipaddr, s + pos, 1);
        strncat(g_ipaddr, ".", 1);
        dfs(s, pos + 1, step + 1);
        memset(g_ipaddr + pos + step, 0, sizeof(g_ipaddr) - (pos + step)); //清空刚才填进去的数据
    } else if (s[pos] == '0') {
        strncat(g_ipaddr, s + pos, 1);
        strncat(g_ipaddr, ".", 1);
        dfs(s, pos + 1, step + 1);
        memset(g_ipaddr + pos + step, 0, sizeof(g_ipaddr) - (pos + step)); //清空刚才填进去的数据
        return;
    } else {
        return;
    }
    // 使用两位数
    if (pos + 1 <= strlen(s) - 1 ) {
        strncat(g_ipaddr, s + pos, 2);
        strncat(g_ipaddr, ".", 1);
        dfs(s, pos + 2, step + 1);
        memset(g_ipaddr + pos + step, 0, sizeof(g_ipaddr) - (pos + step)); //清空刚才填进去的数据
    } else {
        return;
    }
    // 使用三位数
    if ((pos + 2 <= strlen(s) - 1 ) && ((s[pos] - '0')*100 + (s[pos+1] - '0')*10 + (s[pos+2] - '0')  <= 255)) {
        strncat(g_ipaddr, s + pos, 3);
        strncat(g_ipaddr, ".", 1);
        dfs(s, pos + 3, step + 1);
        memset(g_ipaddr + pos + step, 0, sizeof(g_ipaddr) - (pos + step)); //清空刚才填进去的数据
    } else {
        return;
    }
}

char ** restoreIpAddresses(char * s, int* returnSize){
    if ((strlen(s) < 4) || (strlen(s) > 12)) {
        *returnSize = 0;
        return NULL;
    }
    g_count = 0;
    dfs(s, 0, 0);
    *returnSize = g_count;
    return g_ipAdrs;
}