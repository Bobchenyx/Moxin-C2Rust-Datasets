int romanToInt(char * s){
    int result = 0;

    while(*s != '\0'){
        switch(*s){
            case 'I':
                if(*(s + 1) == 'V'){
                    s = s +2;
                    result += 4;
                    break;
                }
                else if(*(s + 1) == 'X'){
                    s = s + 2;
                    result += 9;
                    break;
                }
                else{
                    s = s + 1;
                    result += 1;
                    break;
                }
            case 'V':
                s = s + 1;
                result += 5;
                break;
            case 'X':
                if(*(s + 1) == 'L'){
                    s = s + 2;
                    result += 40;
                    break;
                }
                else if(*(s + 1) == 'C'){
                    s = s + 2;
                    result += 90;
                    break;
                }
                else{
                    s = s + 1;
                    result +=10;
                    break;
                }
            case 'L':
                s = s + 1;
                result += 50;
                break;
            case 'C':
                if(*(s + 1) == 'D'){
                    s = s + 2;
                    result += 400;
                    break;
                }
                else if(*(s + 1) == 'M'){
                    s = s + 2;
                    result += 900;
                    break;
                }
                else{
                    s = s + 1;
                    result += 100;
                    break;
                }
            case 'D':
                s = s + 1;
                result += 500;
                break;
            case 'M':
                s = s + 1;
                result += 1000;
                break;
            default:
                break;
        }
    }

    return result;
}