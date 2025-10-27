#define SIZE 100
int longestPalindrome(char * s){
    int slen=strlen(s);
    int i,sum;
    int flag[SIZE]={0};
    for(i=0;i<slen;i++){
        flag[s[i]-'A']++;
    }
    sum=0;
    for(i=0;i<SIZE;i++){
        if(flag[i]%2==0){
            sum+=flag[i];
        }else{
            sum+=flag[i]-1;
        }
    }
    if(sum==slen){
        return sum;
    }else{
        return sum+1;
    }

}