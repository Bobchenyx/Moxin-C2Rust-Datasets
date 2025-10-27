int lengthOfLastWord(char * s){
    if(strlen(s)==0)
    {
        return 0;
    }
    if(s[strlen(s)-1]==' '&&strlen(s)==1)
    {
        return 0;
    }
    int i=(int)(strlen(s))-1;
    int count=0;
    while(i>=0)
    {
        if(s[i]!=' ')
        {
            count++;
            i--;
        }
        else
        {
            if(count>0)
            {
                return count;
            }
            else
            {
                i--;
            }
            
        }
    }
    return count;
}