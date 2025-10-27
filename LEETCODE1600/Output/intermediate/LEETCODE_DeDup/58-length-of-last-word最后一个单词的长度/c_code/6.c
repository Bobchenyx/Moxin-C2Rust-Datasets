int lengthOfLastWord(char * s){
    int i=0,count=0,now=0;
    for(i;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            count++;
            now++;
        }
        else
            now=0;
        if(now<count&&now!=0)
        count=now;
    }
    return count;
}