int lengthOfLastWord(char * s){

    int last = strlen(s);
    if(last==0) return 0;
    int p=0;
    int i;
    for(i=last;i>=-1;i--)
    {
        if(i==-1) break;
        if(s[i]!='\0'&&s[i]!=' ') break;
    }
    
    if(i==-1) return 0;
    // s[i] 是最后一个单词尾字母
    int num=0;
    while(s[i--]!=' ')
    {
        num+=1;
        if(i==-1) break;
        
    }
    return num;
}