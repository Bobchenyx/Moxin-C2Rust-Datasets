char* compressString(char* S){
    int len= strlen(S);
    char*res=(char*)malloc(sizeof(char) * (2 * len));
    char*tmp=(char*)malloc(sizeof(char)*6);
    if(len <= 2)
        return S;
    int cnt = 1;
    res[0] = S[0];
    for(int i =1;i<=len;i++){
        if(S[i] != S[i - 1]){
            int j = 0;
            while(cnt){
                tmp[j++] ='0'+ cnt % 10;
                cnt /= 10;
            }
            strcat(res,tmp);
            res[strlen(res)]=S[i];
            cnt = 1;
        }
        else
            cnt++;
    }
    if (len>strlen(res)) return res;
    return S;
}