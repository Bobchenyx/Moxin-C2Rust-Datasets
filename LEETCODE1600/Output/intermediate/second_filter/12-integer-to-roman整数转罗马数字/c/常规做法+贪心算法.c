#define TYPE_NUM 13
#define RES_LEN 20
char * intToRoman(int num){
	int flag[TYPE_NUM] = {0};
	int type[TYPE_NUM] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char roman[TYPE_NUM][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	char *res = (char *)malloc(RES_LEN * sizeof(char));
	memset(res, 0, RES_LEN);
	int i = 0;
	while(num != 0){
		flag[i] = num / type[i];
		num = num % type[i];
		i++;
	}
	
	for(i = 0; i < TYPE_NUM; i++){
		while(flag[i] > 0){
			strcat(res, roman[i]);
			flag[i]--;
		}
	}
	
	return res;
}