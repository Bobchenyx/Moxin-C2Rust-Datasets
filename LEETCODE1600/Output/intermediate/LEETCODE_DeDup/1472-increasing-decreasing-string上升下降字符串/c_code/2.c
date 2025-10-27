char * sortString(char * s){
    int char_counter[26];
    int len = strlen(s);
    char * sort_str=(char *)malloc(sizeof(char)*(len+1));
    int i = 0, j = 0;
    for(i = 0; i < 26; i++)
    {
        char_counter[i] = 0;
    }
    for(i = 0; i < 26; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(('a'+i)==s[j])
            {
                char_counter[i]++;
            }
        }
    }
    i = 0;
    while(i < len)
    {
        for(j = 0; j < 26; j++)
        {
            if(char_counter[j] != 0)
            {
                sort_str[i++]='a' + j;
                char_counter[j]--;
            }

        }
        for(j = 25;j >= 0; j--)
        {
            if(char_counter[j] != 0)
            {
                sort_str[i++]='a' + j;
                char_counter[j]--;
            }
        }
    }
    sort_str[i] = '\0';
    return sort_str;
}