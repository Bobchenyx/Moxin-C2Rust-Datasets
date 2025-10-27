int lengthOfLastWord(char * s){
    int len=strlen(s);
    int lastwordlength=0;
    for(int i=0; i<len; i++)
    {
        int tmp=0;
        while(s[i]!=' '&&i<len)
        {
            tmp++;
            i++;
        }
        if(tmp!=0)
            lastwordlength=tmp;
    }
    return lastwordlength;
}