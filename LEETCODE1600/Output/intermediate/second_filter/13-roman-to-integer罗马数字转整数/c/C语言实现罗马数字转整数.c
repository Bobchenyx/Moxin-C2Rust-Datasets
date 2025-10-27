int romanToInt(char * s){
//两个数组罗马数字数值与阿拉伯数字数值一一对应
   	int arry[7] = { 1,5,10,50,100,500,1000 };
	char a[] = "IVXLCDM";
	int b=0;
	int n = 0;
	while( s[n]!= '\0') {
		for (int i = 0;i < 7;i++) {   //用for进行查找
			if (s[n] == a[i]) {
				if (s[n] == 'I'&&s[n+1] == 'V') {
					b = b + 4;
					n++;
					break;
				}
				if (s[n] == 'I'&&s[n+1] == 'X') {
					b = b + 9;
					n++;
					break;
				}
				if (s[n] == 'X'&&s[n + 1] == 'L') {
					b = b + 40;
					n++;
					break;
				}
				if (s[n] == 'X'&&s[n+ 1] == 'C') {
					b = b + 90;
					n++;
					break;
				}
				if (s[n] == 'C'&&s[n + 1] == 'D') {
					b = b + 400;
					n++;
					break;
				}
				if (s[n] == 'C'&&s[n+ 1] == 'M') {
					b = b + 900;
					n++;
					break;
				}
				b = b + arry[i];  //累加
				break;
			}
		}
	n++;
	}
	return b;
}