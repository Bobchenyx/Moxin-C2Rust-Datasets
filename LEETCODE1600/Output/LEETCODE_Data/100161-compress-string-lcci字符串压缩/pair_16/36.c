char res[100010];
char tmp[50010];
char* compressString(char* S){
    int l = strlen(S);
    if(l <= 2)
        return S;
    int cnt = 1;
    int pos = 1;
    res[0] = S[0];
    for(int i = 1;i < l; ++i){
        if(S[i] != S[i - 1]){
            int j = 0;
            while(cnt){
                tmp[j++] = '0' + cnt % 10;
                cnt /= 10;
            }
            for(int k = j - 1;k >= 0; --k)
                res[pos++] = tmp[k];
            res[pos++] = S[i];
            cnt = 1;
        }
        else
            ++cnt;
    }
    int j = 0;
    while(cnt){
        tmp[j++] = '0' + cnt % 10;
        cnt /= 10;
    }
    for(int k = j - 1;k >= 0; --k)
        res[pos++] = tmp[k];
    res[pos] = '\0';
    if(pos < l)
        return res;
    else 
        return S;
}