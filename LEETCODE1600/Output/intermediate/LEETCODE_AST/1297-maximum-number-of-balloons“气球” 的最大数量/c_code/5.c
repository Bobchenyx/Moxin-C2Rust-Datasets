int maxNumberOfBalloons(char * text){
    int charNum[26] = {0};
    char* p = text;
    while(*p != '\0') {
        charNum[*p - 'a']++;
        p++;
    }

    charNum['l'-'a'] = charNum['l'-'a'] / 2;
    charNum['o'-'a'] = charNum['o'-'a'] / 2;

    int ret = charNum['b'-'a'];
    if(ret > charNum['a'-'a']) ret = charNum['a'-'a'];
    if(ret > charNum['l'-'a']) ret = charNum['l'-'a'];
    if(ret > charNum['o'-'a']) ret = charNum['o'-'a'];
    if(ret > charNum['n'-'a']) ret = charNum['n'-'a'];
    
    return ret;
}