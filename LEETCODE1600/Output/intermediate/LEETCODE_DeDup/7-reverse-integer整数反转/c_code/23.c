int reverse(int x){
    int mod = 0;
    long y = 0;
    int i = 0;
	int MAX = 2147483646;
	int MIN = -2147483647;

	if((x < MIN) || (x > MAX))
	{
        return 0;
	}

    while(x != 0) {
        mod = x % 10;
        x = (int)(x / 10);
		if(((y*10 + mod) < MIN) || ((y*10 + mod) > MAX)) {
		    return 0;
		}

        y = y * 10 + mod;
    }

	return y;
}