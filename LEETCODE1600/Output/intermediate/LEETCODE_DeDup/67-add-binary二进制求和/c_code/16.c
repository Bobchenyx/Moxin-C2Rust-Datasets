char *addBinary(char * a,char * b){
    int len, lena=strlen(a), lenb=strlen(b), carry=0, i=lena-1, j=lenb-1,k,num;
    len=lena>lenb?lena+1:lenb+1;
    char* ans=(char*)malloc(sizeof(char)*(len+1));
    ans[0]='0';
    ans[len]='\0';
    k=len-1;
    while(i>-1||j>-1||carry){
        num=(i>-1?a[i]-'0':0)+(j>-1?b[j]-'0':0)+carry;
        carry=0;
        if(num>1){
            carry=1;
            num=num-2;
        }
        ans[k--]=num+'0';
        j--;
        i--;
    }
    if(ans[0]=='0'){
        for(i=0; i<len-1;i++)
            ans[i]=ans[i+1];
        ans[len-1]='\0';      
    }
    return ans;
}