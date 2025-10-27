char * sortString(char * s){
    int* cnt = (int*)malloc(sizeof(int)*26);
    memset(cnt,0,sizeof(int)*26);
    int len = strlen(s);
    int i = len,j=0;
    while(i--)  cnt[ s[i] - 'a']++;
    for(i = 0;i<len;){
        for(j = 0 ; j<26&&i<len ; j++){
            if(cnt[j]>0){
                s[i++] = 'a' + j;
                cnt[j]--;
            }
        }
        for(j=25 ; j>=0 && i<len ; j--){
            if(cnt[j]>0){
                s[i++] = 'a' + j;
                cnt[j]--;
            }
        }
    }
    return s;
}