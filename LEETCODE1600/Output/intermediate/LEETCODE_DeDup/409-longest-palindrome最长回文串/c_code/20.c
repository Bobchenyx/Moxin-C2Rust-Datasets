int longestPalindrome(char * s){
    int count[128] = {0};
    int res = 0;
    int len = strlen(s);
    for(int i=0;i<len;i++)
        count[s[i]]++;
    for(int i=0;i<len;i++)
    {
        res += count[s[i]]/2 *2;  //字母是偶数个时，则全部加入；奇数时，则加入偶数个
        if(count[s[i]]%2==1 && res%2==0)//中心点唯一的情况，即加入该字符，长度为奇数
            res++;
        count[s[i]] = 0;
    }
    return res;
}