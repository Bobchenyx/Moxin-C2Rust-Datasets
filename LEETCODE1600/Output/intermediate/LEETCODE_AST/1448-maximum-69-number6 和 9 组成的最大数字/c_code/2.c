int maximum69Number (int num){
    char* s;
    int len;
    int i;
    s = (char*)malloc(sizeof(char)*5);
    sprintf(s,"%d",num);
    len = strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i] == '6')
        {
            num = num + (int)(pow(10,len-i-1)) * 3;
            free(s);
            return num;
        }
    }
    free(s);
    return num;
}