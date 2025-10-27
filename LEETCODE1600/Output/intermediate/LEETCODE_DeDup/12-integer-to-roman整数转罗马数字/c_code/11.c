struct hash
{
	int  interger;
	char roman[4];
}Hash[13] = {
	1000,"M",
	900,"CM",
	500,"D",
	400,"CD",
	100,"C",
	90,"XC",
	50,"L",
	40,"XL",
	10,"X",
	9,"IX",
	5,"V",
	4,"IV",
	1,"I",
};
char* intToRoman(int num) {
	char cRoman[16] = { 0 };
	char* pcRoman = (char *)malloc(sizeof(cRoman));
	unsigned short uIndex = 0;
	for (uIndex = 0; uIndex <= (13 - 1); uIndex++)
	{
		while (num >= Hash[uIndex].interger)
		{
			num = num - Hash[uIndex].interger;
			strcat(cRoman,Hash[uIndex].roman);
		}
	}
	strcpy(pcRoman, cRoman);
	return pcRoman;
}