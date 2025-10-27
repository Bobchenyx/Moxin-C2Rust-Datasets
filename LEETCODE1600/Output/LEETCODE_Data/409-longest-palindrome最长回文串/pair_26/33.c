int longestPalindrome(char * s){
    int sum=0,length=strlen(s);
    char *keep=(char*)malloc(sizeof(char)*(length+1));
    memset(keep,0,sizeof(char)*(length+1));
    int i,j,index=0;
    for(i=0;i<length;i++){
        for(j=0;j<index;j++){
            if(keep[j]=='0')
                continue;
            if(keep[j]==s[i]){
                keep[j]='0';
                sum+=2;
                break;
            }
        }
        if(j>=index)
            keep[index++]=s[i];
    }
    for(i=0;i<index;i++)
        if(keep[i]!='0'){
            sum++;
            break;
        }
    return sum;
}