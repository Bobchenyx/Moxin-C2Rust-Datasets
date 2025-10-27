int lengthOfLastWord(char * s){
    int index = 0;
    int count = 0;
    int lastCount = 0;
    while(*(s + index) != '\0') {
        if(*(s + index) == ' ') {
            if(count != 0) {
                lastCount = count;
            }
            count = 0;
        } else {
            count ++;
        }
        index++;
    }
    return count == 0? lastCount: count;
}