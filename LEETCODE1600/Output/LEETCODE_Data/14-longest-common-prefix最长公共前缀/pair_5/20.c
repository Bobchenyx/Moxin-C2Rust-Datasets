char * longestCommonPrefix(char ** strs, int strsSize){
    int i, temp, len = 0;
    char *pre;   
    if(strsSize <1)
        return "";
    len = strlen(strs[0]);
    char result[len + 1];
    pre = malloc(sizeof(char) * (len + 1));
    pre = result;
    while(strs[0][i] != '\0')
    {
        temp = 0;
        for(int j = 0;j < strsSize;j++)
        {
            if(strs[0][i] == strs[j][i])
                temp++;
            else               
                break;            
        }
        if(temp != strsSize)
            break;
        else
        {
            result[i] = strs[0][i];
            i++; 
        }
      
    } 
    result[i] = '\0';
    return pre;

}