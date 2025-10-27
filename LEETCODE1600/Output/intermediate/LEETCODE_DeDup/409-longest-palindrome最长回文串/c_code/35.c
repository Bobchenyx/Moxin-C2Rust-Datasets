int longestPalindrome(char * s){
    int letters[52]={0};
    int length=0;
    int center=0;
    int i;
    for(i=0;s[i]!='\0';i++)
        isupper(s[i])?letters[s[i]-'A'+26]++:letters[s[i]-'a']++;
    
    for(i=0;i<52;i++)
        if(letters[i]%2)
            {length+=letters[i]-1;
            center=1;}
        else
            length+=letters[i];
    return length+center;


}