int chartoint(char a);

int romanToInt(char * s){
    int result = 0;
    for (int n = 0; s[n]; n++)
    {
        if (chartoint(s[n]) < chartoint(s[n+1]) )
        {
            result += (chartoint(s[n+1]) - chartoint(s[n]));
            n++;
        }
        else  
         result += chartoint(s[n]);
    }
    return result;
}

int chartoint(char a) {
    int out;
    switch(a)
    {
        case 'I' : out = 1; break;
        case 'V' : out = 5; break;   
        case 'X' : out = 10; break;
        case 'L' : out = 50; break;
        case 'C' : out = 100; break;
        case 'D' : out = 500; break;
        case 'M' : out = 1000; break;
    }
    return out;
}