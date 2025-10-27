void analyzeString(char *s,char *pbuf) {
    int len = strlen(s);
    int arr[10] = {0};
    int pre_value = -1;
    int cur;
    int buflen = 0;
    for (int i = 0; i < len; i++) {
        cur = s[i] - '0';
        if (arr[cur] == 0) {
            if (pre_value != -1) {
                buflen += sprintf(pbuf + buflen,"%d%c",arr[pre_value],'0'+pre_value);
                arr[pre_value] = 0;                            
            }
            pre_value = cur;            
        } 
        arr[cur]++;
    }
    if (0 != arr[cur]) {
        sprintf(pbuf + buflen,"%d%c",arr[cur],'0'+cur);
    }
    return pbuf;
}
char * countAndSay(int n){
    char *pCurCount = malloc(5000 * sizeof(char));
    char *pLastResult = malloc(5000 * sizeof(char));
    memset(pCurCount,0,5000);
    memset(pLastResult,0,5000);
    pLastResult[0] = '1';
    pCurCount[0] = '1';
    for (int i = 1;i < n; i++) {
        memset(pCurCount,0,5000);
        analyzeString(pLastResult,pCurCount);
        memset(pLastResult,0,5000);
        memcpy(pLastResult,pCurCount,strlen(pCurCount));
    }
    return pCurCount;
}