int lengthOfLastWord(char * s){
    int start = -1;
    int end = -1;
    int length = strlen(s);
    for(int i = length-1; i > -1; i--){
        if(end == -1 && s[i] != ' '){
            end = i;
        }
        if(end != -1 && s[i] == ' '){
            start = i;
            break;
        }
    }
    return end-start;
}