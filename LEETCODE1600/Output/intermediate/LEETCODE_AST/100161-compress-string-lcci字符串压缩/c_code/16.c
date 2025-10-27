/*使用双指针进行扫描
1.快指针指向重复的数据，慢指针进行数据计算*/
char* compressString(char* S){
    int sLen = strlen(S);
    if (sLen < 2){
        return S;
    }
    char tmp[sLen * 2];
    int slow = 0;
    int fast = 0;
    int cnt = 1;
    for (int i = 0; i < sLen; i++){
        if (i != sLen - 1 && S[i] == S[i + 1]){
            cnt++;
        } else {
            tmp[slow++] = S[i];
            int num = sprintf(tmp + slow, "%d", cnt);
            slow += num;
            cnt = 1;
        }
    }
    if (slow < sLen){
        strncpy(S, tmp, slow);
        S[slow] = '\0';
    }
    return S;
}