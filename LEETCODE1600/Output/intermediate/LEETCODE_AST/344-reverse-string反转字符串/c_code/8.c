void reverseString(char* s, int sSize){
    int temp = 0;
    int i = 0;

    for (i=0; i<(sSize+1)/2; i++) {
        temp = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = temp;
    }
}