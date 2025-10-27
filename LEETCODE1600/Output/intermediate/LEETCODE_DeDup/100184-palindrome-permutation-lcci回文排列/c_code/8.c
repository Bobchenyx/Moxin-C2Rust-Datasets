bool canPermutePalindrome(char* s){
    int k=strlen(s);
    if(k<=1) return true;
    int i,j,count,x=0;
    for(i=0;i<k-1;i++){
        count=1;
        for(j=i+1;j<k;j++){
            if(s[j]!='#'&&s[i]==s[j]){
                count++;
                s[j]='#';
            }
        }
        if(count%2==0) x=x+count;
        else x=count-1+x;
    }
    if(k%2!=0) x=x+1;
    if(x==k) return true;
    else return false;

}