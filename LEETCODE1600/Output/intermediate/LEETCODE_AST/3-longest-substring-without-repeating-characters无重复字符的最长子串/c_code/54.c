int max (int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int lengthOfLongestSubstring(char * s){

    if (s == NULL || strlen(s) == 0)
        return 0;
    
    int l = 0, r = 0;
    int asciiArr[256] = {0}; // 用ascii值作为字母的数组下标，记录该字母出现的次数
    int res = 0;
    
    while (l < strlen(s))
    {
        if (r < strlen(s) && asciiArr[s[r]] == 0) //当前是否有重复，没有就移动o右指针
        {
            asciiArr[s[r]] ++;
            r++;
        }
        else //有重复，移动左指针
        {
            asciiArr[s[l]] --;
            l++;
        }
                
        res = max(res, r - l);
    }
    
    return res;
}