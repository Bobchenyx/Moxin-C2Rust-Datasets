int lengthOfLastWord(char * s){
    int sLen = strlen(s);
    int index = 0;

    for (int i = sLen - 1; i >= 0; i--) {
        if(s[i] == ' ' && index == 0) {
            continue;            
        } else if (s[i] == ' ') {
            break;
        }
        index++;        
    }

    return index;
}