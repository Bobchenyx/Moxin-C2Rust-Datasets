char * longestPalindrome(char * s){
    int i,j,single,start=0,end=0,len,longest=1;
    if(strlen(s)==0||strlen(s)==1) return s;
    for(i=0;s[i+2]!='\0';i++){
        if(s[i]==s[i+1]||s[i]==s[i+2]){
            if(s[i]==s[i+1]&&s[i]==s[i+2]){
                for(j=3;s[i+j]==s[i];j++);
                single=j%2==1?1:0;
                i=i+j/2-1;
            }else single=s[i]==s[i+2]?1:0;
            for(j=0;i-j>=0&&s[i+j+single+1]!='\0';j++){
                if(s[i-j]!=s[i+j+single+1]) break;
            }
            len=2*j+single;
            if(len>longest){
                longest=len;
                start=i-j+1;
                end=i+j+single;
            }
        }
    }
    if(s[i]==s[i+1]&&longest==1){
        start=i;
        end=i+1;
    }
    s[end+1]='\0';
    return s+start;
}