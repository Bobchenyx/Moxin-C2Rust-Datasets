int doto(int * num){
    int count=0;
    for(int i=0;i<26;i++)
       if(num[i]%2==1)count++;
    return count;
}
int longestPalindrome(char * s){
    int n=strlen(s);
    int numMin[26]={0},numMax[26]={0};
    while(*s!='\0'){
        if(*s>='a')numMin[*s-'a']++;
        else numMax[*s-'A']++;
        s++;
    }
    int a=(doto(numMax)+doto(numMin));
    int tep=(a==0)?n:(n-a+1);
    return tep;
}