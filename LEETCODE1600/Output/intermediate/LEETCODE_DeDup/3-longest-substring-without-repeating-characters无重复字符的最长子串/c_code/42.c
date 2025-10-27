int lengthOfLongestSubstring(char * s){
    if(strlen(s)==1) return 1;
    int maxLength=0,i,j,start,end;
    int hash[128];
    memset(hash,-1,sizeof(hash));
    start=0;
    end=0;
    while(s[end]!='\0'){
        // 仅当s[start,end) 中存在s[end]时更新start
        if(hash[s[end]]>=start){
            start=hash[s[end]];
            start++;
        }
        hash[s[end]]=end;
        end++;
        int length=end-start;
        if(maxLength<length) maxLength=length;
        // printf("start=%d\tend=%d\n",start,end);
    }
    return maxLength;
    

}