int romanToInt(char * s){
    int sum = 0;

    while(*s != '\0') {
        switch (*s) {
            case 'I':
                sum = (*(s+1) == 'V' || *(s+1) == 'X') ? (sum - 1) : (sum + 1);
                break;
            case 'V':
                sum = sum + 5;
                break;
            case 'X':
                sum = (*(s+1) == 'L' || *(s+1) == 'C') ? (sum - 10) : (sum + 10);
                break;
            case 'L':
                sum = sum + 50;
                break;
            case 'C':
                sum = (*(s+1) == 'D' || *(s+1) == 'M') ? (sum - 100) : (sum + 100);
                break;
            case 'D':
                sum = sum + 500;
                break;
            case 'M':
                sum = sum + 1000;
                break;
        }
        s++;
    }
    
    return sum;
}