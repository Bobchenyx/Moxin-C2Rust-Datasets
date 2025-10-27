int getValue(char e)
{
    switch(e){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: break;
    }
    return 0;
}

int romanToInt(char * s){
    int n = strlen(s);
    int num = 0;
    for(int i = 0; i < n; i++){
        int next = i + 1;
        if(next < n && getValue(s[next]) > getValue(s[i])){
            num -= getValue(s[i]);
        } else{
            num += getValue(s[i]);
        }
    }
    return num;
}