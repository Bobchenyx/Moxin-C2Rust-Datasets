int countCharacters(char ** words, int wordsSize, char * chars){
    int result = 0;
        int sign[26] = {0,};
    for(int i=0;chars[i]!='\0';i++){
        sign[chars[i]-'a']++;
    }
    for(int i=0;i<wordsSize;i++){
        int temp[26] = {0,};
        int count = 0;
        for(int j=0;words[i][j]!='\0';j++){
            temp[words[i][j]-'a']++;
        }
        for(int j=0;j<26;j++){
            count += temp[j];
            if(temp[j] > sign[j]){
                count = 0;
                break;
            }
        }
        result += count;
    }
    return result;
}