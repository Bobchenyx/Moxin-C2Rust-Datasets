char findTheDifference(char * s, char * t)
{
    int i;
    char c=0x00;
    for(i=0;i<strlen(s);i++)
    {
        c+=t[i]-s[i];
    }
    return c+t[i];
}