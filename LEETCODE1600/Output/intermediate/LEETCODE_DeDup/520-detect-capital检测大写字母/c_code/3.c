bool detectCapitalUse(char * word){
    int len = strlen(word);
    int i, capital = 0;
    for (i = 0; i < len; ++i) {
        if (word[i] < 'a' && capital++ < i) return false;
    }
    return capital == len || capital < 2;
}