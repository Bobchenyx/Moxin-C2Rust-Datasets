int minimumLengthEncoding(char ** words, int wordsSize){
    bool flag=false;
    int i, j, k1, k2, res=0, new_wordsSize=0;
    char **new_words = (char**)malloc(sizeof(char*)*wordsSize);
    for(i=0; i<wordsSize; i++){
        for(j=0; j<new_wordsSize; j++){
            flag = true;
            k1=strlen(words[i]);
            k2=strlen(new_words[j]);
            // 判断是否是一样的尾部
            while(k1>=0 && k2>=0){
                if(words[i][k1--] != new_words[j][k2--]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                if(k1>=0){  // 如果一样的尾部但words里的单词比new_words的单词长，则替换
                    res += (k1-k2);
                    new_words[j] = words[i];
                }
                break;
            }
        }
        // 如果是新单词，则加入到new_words里
        if(!flag){
            res += (strlen(words[i])+1);
            new_words[new_wordsSize++] = words[i];
        }
    }
    return res;
}