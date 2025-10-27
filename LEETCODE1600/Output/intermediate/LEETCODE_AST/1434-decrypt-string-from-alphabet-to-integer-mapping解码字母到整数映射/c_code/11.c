char * freqAlphabets(char * s){
    int len=strlen(s);
    int cnt=0;
    char *p=(char*)calloc(sizeof(char),len+1);
    for(int i=0;s[i];)
    {
        if((i+2)<len&&s[i+2]=='#')              //双数位置
        {
            p[cnt++]=(s[i]-48)*10+s[i+1]-48+96;
            i+=3;
        }
        else                                    //单数位置
        {
            p[cnt++]=s[i]-48+96;
            i++;
        }
    }
    return p;
}