int longestPalindrome(char * s){
    int *newArray;
    char* str = s;
    int i;
    int offset = 0;
    int len = 0;
    int flag = 0;
    if(s == NULL)
        return 0;
    newArray = (int*)malloc(sizeof(int) * 52);
    for( i = 0; i < 52; i++)
    {
        newArray[i] = 0;
    }
    i = 0;
    
    while(str[i] != '\0')
    {
        if((str[i] >= 'a') && (str[i] <= 'z'))
        {
            offset = str[i] - 'a';
            newArray[offset] += 1;
        }
        else if((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            offset = 26 + str[i] -'A'; 
            newArray[offset] += 1;
        }
        else
        {
            
        }
        i++;
    }
    // string length
    len = 0;
    for( i = 0; i < 52; i++ )
    {
        len += (newArray[i] >> 1);
        if((newArray[i] % 2) == 1)
            flag = 1;
    }
    free(newArray);
    return len * 2 + flag;
}