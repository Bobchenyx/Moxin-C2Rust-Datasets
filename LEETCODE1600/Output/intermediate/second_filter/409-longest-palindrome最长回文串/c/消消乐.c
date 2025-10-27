c []
int longestPalindrome(char * s){
    int len = strlen(s);
    int reuslt = 0;
    long long dispel = 0;
    long long position = 0;
    for(int i=0; i<len;i++){
        position = 1LL <<(s[i]-'A');
        if(dispel& position)    reuslt+=2;
        dispel ^= position;
    }    

    if(dispel > 0) reuslt++;
    return reuslt;
}