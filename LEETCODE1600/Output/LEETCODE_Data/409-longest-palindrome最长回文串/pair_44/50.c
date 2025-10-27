int longestPalindrome(char * s){
    int a[150]={0}, i, cnt=0, flag=0;
    for(i=0;s[i]!='\0';i++){
        a[s[i]]++;
    }
    for(i=0;i<150;i++){
        if(a[i]>0 && a[i]%2==0) {
            cnt+=a[i];
            a[i]=0;
        }
        if(a[i]%2!=0)
        {
            flag=1;
            cnt+=a[i]-1;
        }
    }
   if(flag==1) cnt++;
    return cnt;
}