char findTheDifference(char * s, char * t){
    int sum = 0;
    while(*s){
        sum ^= (*s);
        s ++;
    }
    while(*t){
        sum ^= (*t);
        t ++;
    }

    return (char)sum;
}