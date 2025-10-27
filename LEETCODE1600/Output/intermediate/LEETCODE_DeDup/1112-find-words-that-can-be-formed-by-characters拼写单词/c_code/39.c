int countCharacters(char ** words, int wordsSize, char * chars){
    int output=0;
    int clen=strlen(chars);
    for(int i=0;i<wordsSize;i++){
        int alphbet[26]={0};
        for(int i=0;i<clen;i++){
            char c=chars[i];
            alphbet[c-'a']++;
        }
        int wslen=strlen(words[i]);
        int flag=0;
        for(int j=0;j<wslen;j++){
            char c=words[i][j];
            if(alphbet[c-'a']!=0){
                alphbet[c-'a']--;
            }else{
                flag=1;
                break;//组成不了
            }
        }
        if(flag==0){
            output+=wslen;
        }
    }
    return output;
}