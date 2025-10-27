char findTheDifference(char * s, char * t){
    char result = 0;
    while((*s)!=0)
    {
        result ^= (*t)^(*s);
        s++;t++;
    }
    return result^(*(t));
}