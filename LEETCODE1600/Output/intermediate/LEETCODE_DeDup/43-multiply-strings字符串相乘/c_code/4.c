// 反转字符串中[left,right]区间的字符.
static void reverseString( char s[], int left, int right ) {
	char temp = '\0';

	while( left < right ) {
		temp = s[left];
		s[left++] = s[right];
		s[right--] = temp;
	}
}

// 字符串的模拟加法,将结果存回s1中.
static void additionString( char s1[], char s2[] ) {
	char buf[BUFSIZ] = {'\0'};
	int ib = 0, i1 = 0, i2 = 0, n = 0, jw = 0;

	while( '\0' != s1[i1] || '\0' != s2[i2] || jw > 0 ) {
		n = jw;
		n += '\0' != s1[i1] ? s1[i1++] - '0' : 0;
		n += '\0' != s2[i2] ? s2[i2++] - '0' : 0;
		jw = n < 10 ? 0 : 1;
		n -= n < 10 ? 0 : 10;
		buf[ib++] = n + '0';
	}
	strcpy( s1, buf );
}

char *multiply( char *num1, char *num2 ) {
	int len1 = strlen( num1 ), len2 = strlen( num2 );
	int i1 = 0, i2 = 0;
	int jw = 0, n = 0;
	char buf[BUFSIZ] = {'\0'};
	int bi = 0;
	char *returnArray = NULL;

	if( num1[0] == '0' && num1[1] == '\0' ) { // 例如, num1="0", num2="123".
		return num1;
	}
	if( num2[0] == '0' && num2[1] == '\0' ) { // 例如: num1="123", num2="0".
		return num2;
	}
	if( num1[0] == '1' && num1[1] == '\0' ) { // 例如: num1="1", num2="123".
		return num2;
	}
	if( num2[0] == '1' && num2[1] == '\0' ) { // 例如: num1="123", num2="1".
		return num1;
	}

	returnArray = malloc( sizeof(char) * 54321 );
	returnArray[0] = '\0';

	for( i2 = len2 - 1; i2 >= 0; --i2 ) {
		jw = 0;
		for( bi = 0; bi < len2 - 1 - i2; ++bi  ) { // 补0.
			buf[bi] = '0';
		}
		for( i1 = len1 - 1; i1 >= 0 || jw > 0; --i1 ) {
			n = num2[i2] - '0';
			n *= i1 >= 0 ? num1[i1] - '0' : 0;
			n += jw;
			jw = n / 10;
			n = n % 10;
			buf[bi++] = n + '0';
		}
		buf[bi] = '\0';
		additionString( returnArray, buf ); // 做加法.
	}
	reverseString( returnArray, 0, strlen( returnArray ) - 1 ); // 反转.

	return returnArray;
}