int romanToInt(char * s){
    int count=0,i;
    for(i=0;*(s+i)!='\0';i++){
        if(*(s+i)=='I'&&*(s+i+1)=='V'||*(s+i)=='I'&&*(s+i+1)=='X'||*(s+i)=='X'&&*(s+i+1)=='L'||*(s+i)=='X'&&*(s+i+1)=='C'||*(s+i)=='C'&&*(s+i+1)=='D'||*(s+i)=='C'&&*(s+i+1)=='M'){
            *(s+i)=*(s+i)-1;
        }
        switch (*(s+i)){
            case 'I':
                count+=1;
                break;
            case 'H':
                count-=1;
                break;
            case 'V':
                count+=5;
                break;
            case 'X':
                count+=10;
                break;
            case 'W':
                count-=10;
                break;
            case 'L':
                count+=50;
                break;
            case 'C':
                count+=100;
                break;
            case 'B':
                count-=100;
                break;
            case 'D':
                count+=500;
                break;
            case 'M':
                count+=1000;
                break;
        }
    }
    return count;
}