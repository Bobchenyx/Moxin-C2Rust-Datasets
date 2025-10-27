char * longestCommonPrefix(char ** strs, int strsSize)
{
    int index=0;
    int flag=0;
    if(strsSize==0) return &("");
    while(1)
    {
        for(int i=0;i<strsSize-1;i++)
        {
            if(strs[i][index]!=strs[i+1][index]) flag=1;
        }
        for(int k=0;k<strsSize;k++) if(strs[k][index]=='\0') flag=1;
        if(flag==0) index++;
        else break;
    }
    //printf("%d",index);
    char* res=malloc((index+1)*sizeof(char));
    for(int i=0;i<index;i++)
    {
        res[i]=strs[0][i];
    }
    res[index]='\0';
    return res;
}