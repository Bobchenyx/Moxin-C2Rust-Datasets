int countCharacters(char ** words, int wordsSize, char * chars){
    int len=strlen(words);
    int i,j,k,x,cnt,sum=0;
    int h[26],m[26];
    for(i=0;i<26;i++)
    {
        h[i]=0;
    }
    for(i=0;chars[i]!='\0';i++)
    {
        k=chars[i]-'a';
        h[k]++;
    }
    for(i=0;i<26;i++)
    {
        m[i]=h[i];
    }
    for(i=0;i<wordsSize;i++)
    {
        cnt=0;
        for(j=0;words[i][j]!='\0';j++)
        {
            k=words[i][j]-'a';
            if(h[k]>0)
            {
                cnt++;
                h[k]--;
            }
            else 
            {
                cnt=0;
                break;
            }
        }
        for(x=0;x<26;x++)
        {
            h[x]=m[x];
        }
        sum+=cnt;
    }
    return sum;
}