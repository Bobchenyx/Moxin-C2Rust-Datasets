void reverseString(char* s, int sSize){
    char save;
    int index,i;
    index = sSize/2;
    for(i = 0; i < index; i++)
    {   save = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = save;
    }
}