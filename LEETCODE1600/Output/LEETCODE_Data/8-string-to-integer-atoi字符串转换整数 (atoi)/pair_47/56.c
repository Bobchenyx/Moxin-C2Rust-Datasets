int myAtoi(char * str){

	int flag = 1;
	int have_flag = 0;
	long num = 0;
	int MAX = 2147483647;
	int MIN = -2147483648;

	while (*str == ' ') {
	    str++;
	}

	while((*str < '0') || (*str > '9')) {

		if((*str == '-') || (*str == '+')) {
			if(have_flag) {
			    return 0;
			}

    	    if (*str == '-') {
	            flag = flag * (-1);
				have_flag = 1;
	        }

	        if(*str == '+') {
	            flag = flag * 1;
				have_flag = 1;
	        }
		} 
		else {
		    return 0;
		}
        str++;
	}


	while(('0' <= *str) && (*str <= '9')) {
		num = num * 10 + (int)(*str - '0');	
		if(flag * num < MIN) {
		    return MIN;
		}

        if(flag * num > MAX) {
		    return MAX;
		}
		str++;
	}

	return flag * num;
}