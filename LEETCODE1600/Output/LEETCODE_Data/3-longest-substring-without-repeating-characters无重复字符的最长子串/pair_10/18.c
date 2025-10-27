int lengthOfLongestSubstring(char *s){
    int l,r,maxlen,curlen,length;
    maxlen=0;
    curlen=0;
    length=strlen(s);
    for(r=0;r<length && length-l>maxlen;r++){
        curlen++;         //右边扩展一位，滑窗长度加1
        for(int k=l;k<r;k++)    //从左边开始，索引是否有与最右边相同的字符，y若有，则将窗口左边移到相同字符的下一个字符
        {
            if(s[k]==s[r]){
                   l=k+1;
                   curlen=r-l+1;
                   break;
                 }
                
            }
        if(maxlen<curlen)
        {
            maxlen=curlen;
        }
        }
    
    return maxlen; 
 }