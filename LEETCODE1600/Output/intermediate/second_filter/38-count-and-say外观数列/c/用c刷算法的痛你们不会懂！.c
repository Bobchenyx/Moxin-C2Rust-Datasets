char * countAndSay(int n){
    if(n==1) return "1";
    char temp[31][10000]={'\0'};
    temp[1][0]='1';
    for(int i=2;i<=n;i++){
        int j,pos=0;
        for(j=0;temp[i-1][j]!='\0';){
            int cnt=1,k;
            while(temp[i-1][j++]==temp[i-1][j]) cnt++;
            temp[i][pos++]='0'+cnt;
            temp[i][pos++]=temp[i-1][j-1];
        }
    }
    char *out=temp[n];
    return out;
}