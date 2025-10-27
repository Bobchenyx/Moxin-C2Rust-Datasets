int romanToInt(char * s)
{
	int res = 0;
	while(*s != '\0'){
		if (*s == 'V'){
			res += 5; 
		}else if(*s == 'L'){
			res += 50;
		} else if(*s == 'D'){
			res += 500;
		}else if (*s == 'M'){
			res += 1000;
		}else if (*s == 'I'){
			res = (*(s + 1) == 'V' || *(s + 1) == 'X')? res - 1: res + 1;
		}else if (*s == 'X'){
			res = (*(s + 1) == 'L' || *(s + 1) == 'C')? res - 10: res + 10;
		}else if(*s == 'C'){
			res = (*(s + 1) == 'D' || *(s + 1) == 'M')? res - 100: res + 100;
		}
		s++;
	} 
	return res;
}