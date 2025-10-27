int lengthOfLastWord(char * s){
    int len = strlen(s);
    int i = len - 1;
    
    while(i>=0 && s[i]==' ') i--;   //过滤掉末尾的空格字符
    len = i;
    for(; i>=0 && s[i] != ' '; i--);

    return (i<0 ? len+1 : len-i);
}