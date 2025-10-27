char *intToRoman(int num){
	//罗马数字对应的十进制的数字基本型 
	int base[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	//对应罗马数字的基本型 
	char *str[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
		"V", "IV", "I" };
	char *roman = (char*)malloc(sizeof(char) * 20);//生成一个动态字符数组 20个够了
 	roman[0] = '\0';//把该字符数组变成字符串，不然出问题 
	int i = 0;		//数组遍历 
        //这里没有像分析中那样dif变量，而是用-=  复合赋值
	while (num != 0){ 	//循环一直减   减到为0为止 
		if (num >= base[i]){ //大于该基型的大小 则减之 ，直到下一个基型 
			num -= base[i];
			strcat(roman, str[i]);//把对应的罗马数字加入字符串中 
		}else
			i++;				//减不了  则移动到下一位 
	}
	return roman;				//返回字符串指针 
}