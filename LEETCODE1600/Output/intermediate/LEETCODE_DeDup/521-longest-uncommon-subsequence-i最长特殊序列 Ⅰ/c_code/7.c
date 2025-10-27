int findLUSlength(char * a, char * b){
    if(strlen(a)==strlen(b))
    {
        for(int i=0;i<strlen(a);i++)
        {
            if(a[i]!=b[i])
            {
                return strlen(a);
            }
        }
        return -1;
    }
    else
    {
        return strlen(a)>strlen(b)?strlen(a):strlen(b);
    }
    return 0;
}