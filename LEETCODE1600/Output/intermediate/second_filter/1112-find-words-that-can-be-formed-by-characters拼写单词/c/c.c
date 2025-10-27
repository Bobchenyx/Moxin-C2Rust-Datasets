int countCharacters(char ** words, int wordsSize, char * chars){
    short characters[26] = {0};
    int cnt = 0;
    
    for(int i = 0; i < strlen(chars); i++) 
        characters[chars[i] - 'a']++;
    for(int i = 0; i < wordsSize; i++)
    {
        short cur[26] = {0};
        int mask = 0;
        for(int j = 0; j < strlen(words[i]); j++)
        {
            cur[words[i][j] - 'a']++;
            if(cur[words[i][j] - 'a'] > characters[words[i][j] - 'a'])
            {
                mask = 1;
                break;
            }
            
        }
        if(mask == 0) cnt = cnt + strlen(words[i]);
    }
    return cnt;
}