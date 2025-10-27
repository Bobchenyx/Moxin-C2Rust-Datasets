int longestPalindrome(char * s){
    int buf[128] = {0};
    int i = 0;
    int max_len = 0;
    int flag = 0;
    for(i = 0; i < strlen(s); ++i)
    {
        buf[s[i]] += 1; 
    }

    for(i = 65; i< 128; ++i)
    {
        if(buf[i] > 0)
        {
            if(buf[i] % 2 == 0)
                max_len += buf[i];
            else
            { 
                flag = 1;  // 判断是否有奇数存在
                if(buf[i] > 1)
                {
                    max_len += buf[i] - 1; 
                }
            } 
        }
    }
    if(flag == 1)
        max_len += 1;
    return (max_len);
}