int romanToInt(char * s){
    char *p = s , *q = NULL;
    int sum = 0;
    while(*p){

        if(*p == 'M')
            sum += 1000;
        if(*p == 'D')
            sum += 500;
        if(*p == 'C'){
            q = p;
            q++;
            if(*q == 'D'){
                sum += 400;
                p++;
            }
            else if(*q == 'M'){
                sum += 900;
                p++;
            }
            else
                sum += 100;
        }
        if(*p == 'L')
            sum += 50;
        if(*p == 'X'){
            q = p;
            q++;
            if(*q == 'L'){
                sum += 40;
                p++;
            }
            else if(*q == 'C'){
                sum += 90;
                p++;
            }
            else
                sum += 10;
        }
        if(*p == 'V')
            sum += 5;

        if(*p == 'I'){
            q = p;
            q++;
            if(*q == 'V'){
                sum += 4;
                p++;
            }
            else if(*q == 'X'){
                sum += 9;
                p++;
            }
            else
                sum += 1;
        }

        p++;
        q = NULL;
    }
    return sum;
}