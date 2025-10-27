bool isTail(char *longstr,char *shortstr,size_t longlen,size_t shortlen)
{
    while(shortlen>0)
    {
        if(*(longstr+longlen-1)!=*(shortstr+shortlen-1))
        {
            return false;
        }
        longlen--;
        shortlen--;
    }
    return true;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    bool isNotTail[wordsSize];//标记一下完整的存在于编码中的字符串
    size_t lenOfStrs[wordsSize];
    int ans=0;
    int numOfEncodingStrs=0;
    for(int i=0;i<wordsSize;i++)
    {
        bool hadDownFlag=false;
        size_t ilen=strlen(words[i]);
        lenOfStrs[i]=ilen;
        for(int j=0;j<i;j++)
        {
            if(isNotTail[j])
            {
                size_t jlen=lenOfStrs[j];
                
                if(jlen==ilen)
                {
                    if(strcmp(words[i],words[j])==0)
                    {
                        isNotTail[i]=false;
                        hadDownFlag=true;
                        break;
                    }
                }
                else if(jlen>ilen)
                {
                   // printf("jl>il\n");
                    if(isTail(words[j],words[i],jlen,ilen))
                    {
                        isNotTail[i]=false;
                        hadDownFlag=true;
                        break;
                    }
                }
                else //if(jlen<ilen)
                {
                    if(isTail(words[i],words[j],ilen,jlen))
                    {
                        ans+=ilen-jlen;
                        isNotTail[j]=false;
                        isNotTail[i]=true;
                        hadDownFlag=true;
                        break;
                    }
                }
            }
        }
        if(!hadDownFlag)
        {
            isNotTail[i]=true;
            numOfEncodingStrs++;
            ans+=ilen;
        }
       // printf("%s\n",words[i]);
    }
    ans+=numOfEncodingStrs;
    return ans;
}