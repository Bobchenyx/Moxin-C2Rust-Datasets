bool detectCapitalUse(char * word){
    int capital = 0;
    int lowercase = 0;
    if (word[0] >= 'A' && word[0] <= 'Z'){
        for (int i = 1; i < strlen(word); i++){
            if (word[i] >= 'a' && word[i] <= 'z'){
                capital = 1;
            }
            if (word[i] >= 'A' && word[i] <= 'Z'){
                lowercase = 1;
            }
        }
    }
    else{
        for (int i = 1; i < strlen(word); i++){
            if (word[i] >= 'A' && word[i] <= 'Z'){
                return false;
            }
        }
    }
    if (capital && lowercase)
        return false;
    return true;
}