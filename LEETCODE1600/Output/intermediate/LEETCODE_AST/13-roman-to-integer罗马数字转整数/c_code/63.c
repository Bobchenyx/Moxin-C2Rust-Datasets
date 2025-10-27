int romanToInt(char * s){

    int result = 0;

    enum {i = 1, v = 5, x = 10, l = 50, c = 100, d = 500, m = 1000};

    while(*s != '\0')
    {
        switch(*s)
        {
            case 'M':
                result += m;
                break;
            case 'D':
                result += d;
                break;
            case 'C':
                if(*(s+1) == 'D')
                {
                    result += 400;
                    s++;
                }
                else if(*(s+1) == 'M')
                {
                    result += 900;
                    s++;
                }
                else
                    result += c;
                break;
            case 'L':
                result += l;
                break;            
            case 'X':
                if(*(s+1) == 'L')
                {
                    result += 40;
                    s++;
                }
                else if(*(s+1) == 'C')
                {
                    result += 90;
                    s++;
                }
                else
                    result += x;
                break;
            case 'V':
                result += v;
                break;            
            case 'I':
                if(*(s+1) == 'V')
                {
                    result += 4;
                    s++;
                }
                else if(*(s+1) == 'X')
                {
                    result += 9;
                    s++;
                }
                else
                    result += i;
                break;
            default:
                break;
        }
        s++;
    }
    
	return result;
}