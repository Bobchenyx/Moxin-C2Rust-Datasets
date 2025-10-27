int countCharacters(char ** words, int wordsSize, char * chars){
    int a[26]={0};
    int i=0;
    while(chars[i]!=0){
        a[chars[i]-'a']++;
        i++;
    }
    int sum=0,j=0;
    for(i=0;i<wordsSize;i++){
        j=0;
        while(words[i][j]!=0){
            if(a[words[i][j]-'a']>0){
                a[words[i][j]-'a']--;
            }else{
                break;
            }
            j++;
        }
        if(words[i][j]==0){
            sum+=j;
        }
        j--;
        while(j>=0){
            a[words[i][j]-'a']++;
            j--;
        }
    }
    return sum;
}