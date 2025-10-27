char *intToRoman(int num)
{
	char* map[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}};
	char s[100] = "";
    char *str = s;
	strcpy (s,map[3][num/1000]);
    strcat (s,map[2][num/100%10]);
    strcat (s,map[1][num/10%10]);
    strcat (s,map[0][num%10]);
	return str;
}