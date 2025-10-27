int lengthOfLongestSubstring(char * s){ 
    int maxl=1,clen=0;int begin=0;
    int len=strlen(s);int flag=0;
    if(len==0) return 0;
    if(len==1) return 1;
    int hash[128];
    for(int i=0;i<128;i++) hash[i]=-1;
    for(int i=0;i<len;i++){
        int a=s[i];
        if(hash[a]==-1||begin>hash[a]) {
         hash[a]=i;
         clen++;
         if(i+1<len&&s[i+1]==s[i]){
             if(clen>maxl) maxl=clen;
                for(int i=0;i<128;i++) hash[i]=-1;
                 clen=0;begin=i+1;continue;
            }
        }
        else {
            //if(clen>maxl) maxl=clen;
            if(i+1<len&&s[i+1]==s[i]){
                for(int i=0;i<128;i++) hash[i]=-1;
                 clen=0;begin=i+1;continue;
            }
            clen=i-hash[a];
            begin=hash[a]+1;
            hash[a]=i;
        }
        if(clen>maxl) maxl=clen;
    }
    
    return maxl;
}