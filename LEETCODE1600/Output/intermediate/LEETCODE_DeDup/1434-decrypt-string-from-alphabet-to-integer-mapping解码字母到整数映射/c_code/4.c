char * freqAlphabets(char * s){
    //入参检查
    if(!s)
    {
        return NULL;
    }

    //分配并初始化数组
    int len = strlen(s);
    char *result = (char*)malloc(sizeof(char)*len);
    memset(result,0,sizeof(char)*len);

    //循环遍历原数组，并替换字符串
    int k =0;
    for(int i=0; i<strlen(s); i++)
    {
        if(((i+2)<strlen(s)) && (s[i+2] == '#'))
        {
            result[k] = (s[i]-'0')*10+(s[i+1]-'1')+'a';
            k++;
            i+=2;
        }
        else
        {
            result[k] = s[i] - '1' + 'a';
            k++;
        }
    }
    return result;
}