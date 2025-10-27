bool detectCapitalUse(char * word){
    #define ISUPPER(c) (((c>='A')&&(c<='Z')) ? 1:0)
    #define ISLOWER(c) (((c>='a')&&(c<='z')) ? 1:0)
    #define True 1
    #define False 0
    int len = strlen(word);
    int i;
    if(len == 1) return True;
    if(ISLOWER(*word))
    {
        for(i=1;i<len;i++)
        {
            if(ISLOWER(*(word+i))) continue;
            else return False;
        }
        return True;
    }
    if(ISUPPER(*word))
    {
        if(ISUPPER(*(word+1)))
        {
            for(i=2;i<len;i++)
            {
                if(ISUPPER(*(word+i))) continue;
                else return False;
            }
            return True;
        }
        if(ISLOWER(*(word+1)))
        {
            for(i=2;i<len;i++)
            {
                if(ISLOWER(*(word+i))) continue;
                else return False;
            }
            return True;
        }
    }
    return True;

}