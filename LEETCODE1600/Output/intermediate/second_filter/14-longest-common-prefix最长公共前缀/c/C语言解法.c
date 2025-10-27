char * longestCommonPrefix(char ** strs, int strsSize)
{
    int i,j;
    if(strsSize<1)
    return "";
    for(i=0;strs[0][i]!='\0';i++)
    {
        //k++;
        for(j=1;j<strsSize;j++)
        {
            if(strs[j][i]!=strs[0][i])
            {strs[0][i]='\0';
            return strs[0];
            }
        }
        
    }
    return strs[0];
}