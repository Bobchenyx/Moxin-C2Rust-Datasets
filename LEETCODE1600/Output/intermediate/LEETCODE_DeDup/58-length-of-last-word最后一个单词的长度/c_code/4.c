int lengthOfLastWord(char * s){
    int length = 0, tmp = 0;
    int i = 0;

    while(s[i] != '\0')
    {
        if(s[i] != ' ')
        {
            tmp++;
        }
        else
        {
            if(tmp)
            {
                length = tmp;
            }

            tmp = 0;
        }
        
        i++;
    }

    if(tmp)
    {
        length = tmp;
    }

    return length;
}