int romanToInt(char * s){
    int rst=0;
    while(*s!='\0'){
        char c=*s;
        s++;
        if(c=='I'){
            if(*s=='V'){
                s++;
                rst+=4;
                continue;
            }
            if(*s=='X'){
                s++;
                rst+=9;
                continue;
            }
            rst+=1;
            continue;
        }
        if(c=='X'){
            if(*s=='L'){
                s++;
                rst+=40;
                continue;
            }
            if(*s=='C'){
                s++;
                rst+=90;
                continue;
            }
            rst+=10;
            continue;
        }
        if(c=='C'){
            if(*s=='D'){
                s++;
                rst+=400;
                continue;
            }
            if(*s=='M'){
                s++;
                rst+=900;
                continue;
            }
            rst+=100;
            continue;
        }
        switch(c){
            case 'V':
                rst+=5;
                break;
            case 'L':
                rst+=50;
                break;
            case 'D':
                rst+=500;
                break;
            case 'M':
                rst+=1000;
                break;
        }
        
    }
    return rst;
}