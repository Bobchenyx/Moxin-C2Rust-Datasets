char findTheDifference(char * s, char * t){
    char res=0;
    int len,i;
    len=strlen(s);
    if(len==0){
        return t[0];
    }
    for(i=0;i<len;i++){
        res=res^s[i];
        res=res^t[i];
    }
    res=res^t[len];
    return res;
}